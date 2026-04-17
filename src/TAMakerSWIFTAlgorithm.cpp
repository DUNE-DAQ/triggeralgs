#include "triggeralgs/SWIFT/TAMakerSWIFTAlgorithm.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TriggerActivityMakerSWIFTPlugin"

#include <cassert>
#include <iostream>
#include <cmath>

namespace triggeralgs {

  // configuration
  void TriggerActivityMakerSWIFT::configure(const nlohmann::json& config)
  {
    //window settings
    m_window_length                 = config.value("window_length", 32000); // in DTS ticks (32 * 1000 readout ticks @ 500ns/tick)
    m_inspect_energy_threshold_sadc = config.value("inspect_energy_threshold_sadc", 15000);
    m_accept_energy_threshold_sadc  = config.value("accept_energy_threshold_sadc", 55000);

    //tp filtering settings
    m_min_adc_peak               = config.value("min_adc_peak", 80); //ADC
    m_min_samples_over_threshold = config.value("min_samples_over_threshold", 256); // 8 * 32 DTS ticks while still using TPv1 FIXME

    //clustering
    //these depend on detector properties. default values for HD
    m_cm_per_tick              = config.value("cm_per_tick", 0.016 * 0.16); // sampling rate [us/tick] * drift velocity [cm/us]
    m_wire_pitch               = config.value("wire_pitch", 0.48); // cm
    m_db_min_samples           = config.value("min_samples", 2); //min. number of TPs for valid cluster
    m_db_eps                   = config.value("epsilon", 2); //dbscan search radius in cm
    m_cluster_energy_cut_sadc  = config.value("cluster_energy_cut_sadc", 22000); // min energy of dominant cluster eng. in window for acceptance

    assert(m_window_length > 0);
  }

  //TP refinement
  bool TriggerActivityMakerSWIFT::preprocess( const TriggerPrimitive& input_tp){
    if ((input_tp.adc_peak < m_min_adc_peak) && (input_tp.samples_over_threshold < m_min_samples_over_threshold )) {
      return false;
    }
    return true;
  }

  // Reset window state
  void TriggerActivityMakerSWIFT::reset_window_state(uint64_t new_window_start) {
    m_window_start          = new_window_start;
    m_window_energy_sadc    = 0;
    m_tp_count              = 0;
    m_current_ta            = TriggerActivity(); 
    m_current_ta.time_start = m_window_start;
  }

  //main function for binning TPs into fixed-size time windows
  //assumes TPs are strictly time-ordered
  void TriggerActivityMakerSWIFT::process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_tas)
  {

    // Apply TP filtering
    if (!preprocess(input_tp)) {
      return;
    }

    // If TP is valid, determine which window this TP belongs to
    const uint64_t tp_window_start = (input_tp.time_start / m_window_length) * m_window_length;

    // Initialise on first TP
    if (!m_initialised) {

      //create TA instance once at run start
      m_current_ta = TriggerActivity();

      //reset window state
      reset_window_state(tp_window_start);
      m_initialised = true;
    }

    //if TP belongs to past window (already closed), reject it (not ideal)
    if (tp_window_start < m_window_start){
      return;
    }

    //if TP belongs to future window, close existing TA and start a new one at current time
    if (tp_window_start > m_window_start){
      close_window(output_tas);
      reset_window_state(tp_window_start);
    }

    //If we got here, the TP belongs to the current window
    m_current_ta.inputs.push_back(input_tp);
    m_window_energy_sadc += input_tp.adc_integral;
    ++m_tp_count;
  }

  //function which gets called when the window is closed.
  //main window categorisation & TA generation happens here
  void TriggerActivityMakerSWIFT::close_window(std::vector<TriggerActivity>& output_tas) {

    if (m_current_ta.inputs.empty()) return;

    //Prompt window categorisatoin : immidiate accept, inspect, reject based on local energy in window
    WindowDecision decision;
    if (m_window_energy_sadc >= m_accept_energy_threshold_sadc) decision = WindowDecision::kAccept;
    else if (m_window_energy_sadc >= m_inspect_energy_threshold_sadc) decision = WindowDecision::kInspect;
    else  return; // Reject

    // cluster inspect cases
    if (decision == WindowDecision::kInspect) {
      const uint64_t max_cluster_energy =  extract_dominant_cluster_energy(m_current_ta.inputs, m_db_eps, m_db_min_samples);
      if (max_cluster_energy <= m_cluster_energy_cut_sadc) return; // reject window if it didn't pass inspection
    }

    // Emit TA: should only reach this step if dealing with  Accept, or Inspect windows that passed clustering
    set_ta_attributes();
    output_tas.push_back(m_current_ta);
  }



  //Clustering function: density-based clustering in t-z, where both coordinates are expressed in cm.
  //returns only max eng. for now, as that's the param. based on which decision is made.
  //FIXME eventually want this step to return nclusrers, mean cluster eng. etc.
  uint64_t TriggerActivityMakerSWIFT::extract_dominant_cluster_energy(const std::vector<TriggerPrimitive>& tps, float eps, int min_samples){

    struct Point {
      float z;
      float t;
      uint64_t adc;
    };

    //since time and channel are in different units, express TPs as points in unified coordinate system (z,t)
    std::vector<Point> points;
    points.reserve(tps.size());
    for (const auto& tp : tps) {
      points.push_back({tp.channel * m_wire_pitch, (tp.time_start - m_window_start) * m_cm_per_tick, tp.adc_integral});
    }

    const int N = points.size(); //number of elements to cluster
    int cluster_id = 0;
    std::vector<int> labels(N, -1); // initialise all labels to noise for now
    std::vector<uint8_t> visited(N, 0);
    float eps2 = eps * eps; //clustering radius

    for (int i = 0; i < N; ++i) {
      if (visited[i]) continue;
      visited[i] = 1;

      std::vector<int> neigh;
      const float zi = points[i].z;
      const float ti = points[i].t;
      for (int j = 0; j < N; ++j) {
	float dz = points[j].z - zi;
	float dt = points[j].t - ti;
	if (dz*dz + dt*dt <= eps2) neigh.push_back(j);
      }

      if (neigh.size() < static_cast<size_t>(min_samples)) {
	labels[i] = -1;
	continue;
      }

      labels[i] = cluster_id;

      size_t k = 0;
      while (k < neigh.size()) {
	int j = neigh[k];

	if (!visited[j]) {
	  visited[j] = 1;

	  std::vector<int> neigh2;
	  const float zj = points[j].z;
	  const float tj = points[j].t;
	  for (int m = 0; m < N; ++m) {
	    float dz = points[m].z - zj;
	    float dt = points[m].t - tj;
	    if (dz*dz + dt*dt <= eps2) neigh2.push_back(m);
	  }
	  if (neigh2.size() >= static_cast<size_t>(min_samples)) {
	    for (int m : neigh2) {
	      if (std::find(neigh.begin(), neigh.end(), m) == neigh.end())
		neigh.push_back(m);
	    }
	  }
	}

	if (labels[j] == -1) labels[j] = cluster_id;
	++k;
      }
      ++cluster_id;
    }

    // once clusters are formed, calculate the energies
    std::vector<uint64_t> cluster_sums(cluster_id, 0);
    for (int i = 0; i < N; ++i) {
      if (labels[i] >= 0) cluster_sums[labels[i]] += points[i].adc;
    }
    //return dominant cluster energy in window
    if (cluster_sums.empty()) return 0;
    return *std::max_element(cluster_sums.begin(), cluster_sums.end());
  }


  //TA feature extraction - FIXME most of these fields are somewhat useless
  void TriggerActivityMakerSWIFT::set_ta_attributes()
  {
    m_current_ta.time_start = m_window_start;
    m_current_ta.time_end   = m_window_start + m_window_length;
    m_current_ta.adc_integral = m_window_energy_sadc;

    const TriggerPrimitive& first_tp = m_current_ta.inputs.front();
    m_current_ta.detid = first_tp.detid;
    m_current_ta.type = TriggerActivity::Type::kTPC;
    m_current_ta.algorithm = TriggerActivity::Algorithm::kUnknown; //FIXME


    dunedaq::trgdataformats::channel_t min_ch = first_tp.channel;
    dunedaq::trgdataformats::channel_t max_ch = first_tp.channel;

    // Peak quantities
    m_current_ta.adc_peak = 0;
    for (const auto& tp : m_current_ta.inputs) {
      if (tp.channel < min_ch) min_ch = tp.channel;
      if (tp.channel > max_ch) max_ch = tp.channel;

      if (tp.adc_peak > m_current_ta.adc_peak) {
	m_current_ta.adc_peak = tp.adc_peak;
	m_current_ta.channel_peak = tp.channel;
	m_current_ta.time_peak = tp.time_start;
      }
    }

    m_current_ta.channel_start = min_ch;
    m_current_ta.channel_end   = max_ch;
    m_current_ta.time_activity = m_current_ta.time_peak;

  }


  void TriggerActivityMakerSWIFT::flush(timestamp_t /*until*/, std::vector<TriggerActivity>& output_tas)
  {
    if (!m_initialised) return;
    close_window(output_tas);
  }

  REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TriggerActivityMakerSWIFT)

} // namespace triggeralgs
