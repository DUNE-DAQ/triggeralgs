/**
 * @file TAMakerProtoDUNEBSMWindowAlgorithm.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/ProtoDUNEBSMWindow/TAMakerProtoDUNEBSMWindowAlgorithm.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TAMakerProtoDUNEBSMWindowAlgorithm"

#include <vector>
#include <chrono>

using namespace triggeralgs;
using Logging::TLVL_DEBUG_ALL;
using Logging::TLVL_DEBUG_HIGH;
using Logging::TLVL_DEBUG_LOW;
using Logging::TLVL_IMPORTANT;

void
TAMakerProtoDUNEBSMWindowAlgorithm::process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta)
{
  
  if(m_current_window.is_empty()){
    // Reset window with new TP
    m_current_window.reset(input_tp);
    // Initialise last time an XGBoost prediction was made
    m_last_pred_time = input_tp.time_start;
    // Iterate number of TPs in the window
    m_primitive_count++;
    // First time operator is called set ROP first and last channel
    unsigned int detelement = channelMap->get_element_id_from_offline_channel(input_tp.channel);
    unsigned int plane = channelMap->get_plane_from_offline_channel(input_tp.channel);

    // Are we on the collection plane? Use XGBoost model for collection plane TPs
    // evaluate the sum of the TP charge if on induction planes
    // Induction plane IDs = 0, 1
    // Collection plane ID = 2
    if (plane > 1) m_collection_plane = true;

    // Use PlaneInfo object to get the first and last channels on plane
    PlaneInfo plane_info = m_det_plane_map.get_plane_info(m_channel_map_name, detelement, plane);
    m_first_channel = static_cast<channel_t>(plane_info.min_channel);
    channel_t n_channels_on_plane = static_cast<channel_t>(plane_info.n_channels);

    // If we are in PD-VD use 'effective' channel mapping for CRPs
    // (but only for collection plane)
    if (plane != 2) m_pdvd_map = false;
    if (m_pdvd_map) {
      m_pdvd_eff_channel_mapper = std::make_unique<PDVDEffectiveChannelMap>(plane_info.min_channel, plane_info.n_channels);

      m_first_channel = m_pdvd_eff_channel_mapper->remapCollectionPlaneChannel(m_first_channel);
      m_last_channel = m_first_channel + m_pdvd_eff_channel_mapper->getNEffectiveChannels();
      m_chan_bin_length = m_pdvd_eff_channel_mapper->getNEffectiveChannels() / m_num_chanbins;
    } else { // Running in PD-HD, so don't need effective channel
      m_last_channel = m_first_channel + n_channels_on_plane;
      m_chan_bin_length = n_channels_on_plane / m_num_chanbins;
    }

    TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:BSMW] 1st Chan = " << m_first_channel << ", last Chan = " << m_last_channel << std::endl
      << "Number of channel bins = " << m_num_chanbins << ", and channel bin length = " << m_chan_bin_length;
    return;
  } 
  
  // If the difference between the current TP's start time and the start of the window
  // is less than the specified window size, add the TP to the window.
  if((input_tp.time_start - m_current_window.time_start) < m_window_length){
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:BSMW] Window not yet complete, adding the input_tp to the window.";
    m_current_window.add(input_tp);
  }

  // If the addition of the current TP to the window would make it longer
  // than the specified window length, don't add it
  // First, if these are not collection plane TPs, just evaluate the total charge
  // If the total charge on the induction plane crosses a threshold, create a TA
  else if(!m_collection_plane && m_current_window.adc_integral > m_adc_threshold_induction){
    TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:ADCSW] ADC integral in window is greater than specified threshold.";
    output_ta.push_back(construct_ta());
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:ADCSW] Resetting window with input_tp.";                           
    m_current_window.reset(input_tp);
  }

  // If the addition of the current TP to the window would make it longer
  // than the specified window length, don't add it
  // Check the TPs are on the collection plane - if they are we can use XGBoost
  // Instead check whether it has been long enough since the last XGBoost prediction 
  // then run the model to determine whether to create a TA
  else if (m_collection_plane &&
      (m_current_window.time_start - m_last_pred_time) > m_bin_length && // check enough time has passed since last window
      m_current_window.adc_integral > m_adc_threshold_collection && // set a low minimum threshold for the ADC integral sum
      compute_treelite_classification() // XGBoost classifier 
      )
  {
    TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:BSMW] XGBoost neutrino prob. is greater than specified threshold.";
    output_ta.push_back(construct_ta());
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:BSMW] Resetting window with input_tp.";
    m_current_window.reset(input_tp);
  }
  // If it is not, move the window along.
  else{
    TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:BSMW] Window is at required length but adc threshold not met, shifting window along.";
    m_current_window.move(input_tp, m_window_length);
  }
  
  TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:BSMW] " << m_current_window;

  m_primitive_count++;

  return;

}

void
TAMakerProtoDUNEBSMWindowAlgorithm::configure(const nlohmann::json &config)
{
  if (config.is_object()){
    if (config.contains("channel_map_name")) m_channel_map_name = config["channel_map_name"];
    if (config.contains("adc_threshold_induction")) m_adc_threshold_induction = config["adc_threshold_induction"];
    if (config.contains("bdt_threshold")) {
      uint64_t int_bdt_threshold = config["bdt_threshold"];
      if (int_bdt_threshold <= 100) m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.01);
      else if (int_bdt_threshold <= 1000) m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.001);
      else if (int_bdt_threshold <= 10000) m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.0001);
      else m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.01);
    }
  }
  else{
    TLOG_DEBUG(TLVL_IMPORTANT) << "[TAM:BSMW] The DEFAULT values of window_length and adc_threshold are being used.";
  }
  
  TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:BSMW] Bin length is " << m_bin_length << " for a window of " << m_num_timebins << 
    " bins. ADC threshold across window set to " << m_adc_threshold_induction;
  
  channelMap = dunedaq::detchannelmaps::make_tpc_map(m_channel_map_name);

  // If we are in PD-VD, set boolean to true to enable effective channel mapping
  if (m_channel_map_name == "PD2VDTPCChannelMap" || m_channel_map_name == "PD2VDBottomTPCChannelMap" ||
      m_channel_map_name == "PD2VDTopTPCChannelMap") {
    m_pdvd_map = true;
  } else { // else we are in PD-HD and we use true channel mapping
    m_pdvd_map = false;
  }
 
  // Collection plane ADC threshold fixed by model training
  // Account for PD-HD and PD-VD having different thresholds (for now they are the same)
  if (m_pdvd_map) m_adc_threshold_collection = 200000.;
  else m_adc_threshold_collection = 200000.;

  m_bin_length = static_cast<timestamp_t>(m_window_length / m_num_timebins);

  m_compiled_model_interface = std::make_unique<CompiledModelInterface>(nbatch, m_pdvd_map);

  const size_t num_feature = m_compiled_model_interface->GetNumFeatures();

  flat_batched_inputs.resize(num_feature);

  flat_batched_Entries.clear();
  for (size_t i = 0; i < num_feature; ++i) {
    union Entry zero;
    zero.fvalue = 0.0;
    flat_batched_Entries.emplace_back(zero);
  }
}

TAMakerProtoDUNEBSMWindowAlgorithm::~TAMakerProtoDUNEBSMWindowAlgorithm() {
  // Nothing to clean up
}

TriggerActivity
TAMakerProtoDUNEBSMWindowAlgorithm::construct_ta() const
{
  TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:BSMW] I am constructing a trigger activity!";

  TriggerPrimitive latest_tp_in_window = m_current_window.tp_list.back();
  // The time_peak, time_activity, channel_* and adc_peak fields of this TA are irrelevent
  // for the purpose of this trigger alg.
  TriggerActivity ta;
  ta.time_start = m_current_window.time_start;
  ta.time_end = latest_tp_in_window.time_start + latest_tp_in_window.samples_over_threshold * 32;
  ta.time_peak = latest_tp_in_window.samples_to_peak * 32 + latest_tp_in_window.time_start;
  ta.time_activity = ta.time_peak;
  ta.channel_start = latest_tp_in_window.channel;
  ta.channel_end = latest_tp_in_window.channel;
  ta.channel_peak = latest_tp_in_window.channel;
  ta.adc_integral = m_current_window.adc_integral;
  ta.adc_peak = latest_tp_in_window.adc_peak;
  ta.detid = latest_tp_in_window.detid;
  ta.type = TriggerActivity::Type::kTPC;
  ta.algorithm = TriggerActivity::Algorithm::kUnknown;
  ta.inputs = m_current_window.tp_list;
  return ta;
}

bool TAMakerProtoDUNEBSMWindowAlgorithm::compute_treelite_classification() {
  
  m_last_pred_time = m_current_window.time_start;
  
  m_current_window.bin_window(
      flat_batched_inputs, 
      m_num_timebins, m_bin_length,
      m_num_chanbins, m_chan_bin_length, m_first_channel,
      m_pdvd_eff_channel_mapper, m_pdvd_map
      );
  
  m_current_window.fill_entry_window(flat_batched_Entries, flat_batched_inputs); 
    
  std::vector<float> result(nbatch, 0.0f);
  
  m_compiled_model_interface->Predict(flat_batched_Entries.data(), result.data());
  
  return m_compiled_model_interface->Classify(result.data(), m_bdt_threshold);

}

// Register algo in TA Factory
REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TAMakerProtoDUNEBSMWindowAlgorithm)
