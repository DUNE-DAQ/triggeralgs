/**
 * @file TAMakerADCSimpleWindowAlgorithm.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/ADCSimpleWindow/TAMakerADCSimpleWindowAlgorithm.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TAMakerADCSimpleWindowAlgorithm"

#include <vector>




namespace triggeralgs {

// using namespace triggeralgs;
using Logging::TLVL_DEBUG_ALL;
using Logging::TLVL_DEBUG_HIGH;
using Logging::TLVL_DEBUG_LOW;
using Logging::TLVL_IMPORTANT;

void
TAMakerADCSimpleWindowAlgorithm::Window::add(TriggerPrimitive const &input_tp){
  // Add the input TP's contribution to the total ADC and add it to
  // the TP list.
  adc_integral += input_tp.adc_integral;
  tp_list.push_back(input_tp);
}

void 
TAMakerADCSimpleWindowAlgorithm::Window::move(TriggerPrimitive const &input_tp, timestamp_t const &window_length){
  // Find all of the TPs in the window that need to be removed
  // if the input_tp is to be added and the size of the window
  // is to be conserved.
  // Substract those TPs' contribution from the total window ADC.
  uint32_t n_tps_to_erase = 0;
  for(auto tp : tp_list){
    if(input_tp.time_start-tp.time_start >= window_length){
      n_tps_to_erase++;
      adc_integral -= tp.adc_integral;
    } else {
      break;
    }
  }
  // Erase the TPs from the window.
  tp_list.erase(tp_list.begin(), tp_list.begin()+n_tps_to_erase);

  // Make the window start time the start time of what is now the
  // first TP.
  if(!tp_list.empty()){
    time_start = tp_list.front().time_start;
    add(input_tp);
  } else {
    reset(input_tp);
  }
}


void 
TAMakerADCSimpleWindowAlgorithm::Window::reset(TriggerPrimitive const &input_tp){
  // Empty the TP list.
  tp_list.clear();
  // Set the start time of the window to be the start time of the 
  // input_tp.
  time_start = input_tp.time_start;
  // Start the total ADC integral.
  adc_integral = input_tp.adc_integral;
  // Add the input TP to the TP list.
  tp_list.push_back(input_tp);
}



std::ostream& 
operator<<(std::ostream& os, const TAMakerADCSimpleWindowAlgorithm::Window& window)
{
    if (window.is_empty()) {
        os << "Window is empty!\n";
    } else {
        os << "Window start: " << window.time_start
           << ", end: " << window.tp_list.back().time_start
           << ". Total of: " << window.adc_integral
           << " ADC counts with " << window.tp_list.size()
           << " TPs.\n";
    }
    return os;
}

void
TAMakerADCSimpleWindowAlgorithm::process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta)
{
  
  // The first time operator is called, reset
  // window object.
  if(m_current_window.is_empty()){
    m_current_window.reset(input_tp);
    m_primitive_count++;
    return;
  } 

  // If the difference between the current TP's start time and the start of the window
  // is less than the specified window size, add the TP to the window.
  if((input_tp.time_start - m_current_window.time_start) < m_window_length){
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:ADCSW] Window not yet complete, adding the input_tp to the window.";
    m_current_window.add(input_tp);
  }
  // If the addition of the current TP to the window would make it longer
  // than the specified window length, don't add it but check whether the sum of all adc in
  // the existing window is above the specified threshold. If it is, make a TA and start 
  // a fresh window with the current TP.
  else if(m_current_window.adc_integral > m_adc_threshold){
    TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:ADCSW] ADC integral in window is greater than specified threshold.";
    output_ta.push_back(construct_ta());
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:ADCSW] Resetting window with input_tp.";
    m_current_window.reset(input_tp);
  }
  // If it is not, move the window along.
  else{
    TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:ADCSW] Window is at required length but adc threshold not met, shifting window along.";
    m_current_window.move(input_tp, m_window_length);
  }
  
  TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:ADCSW] " << m_current_window;

  m_primitive_count++;

  return;
}

void
TAMakerADCSimpleWindowAlgorithm::configure(const nlohmann::json& config)
{
  TriggerActivityMaker::configure(config);

  //FIXME use some schema here
  if (config.is_object()){
    if (config.contains("window_length")) m_window_length = config["window_length"];
    if (config.contains("adc_threshold")) m_adc_threshold = config["adc_threshold"];
  }
  else{
    TLOG_DEBUG(TLVL_IMPORTANT) << "[TAM:ADCSW] The DEFAULT values of window_length and adc_threshold are being used.";
  }
  TLOG_DEBUG(TLVL_IMPORTANT) << "[TAM:ADCSW] If the total ADC of trigger primitives with times within a "
                         << m_window_length << " tick time window is above " << m_adc_threshold << " counts, a trigger will be issued.";
}

TriggerActivity
TAMakerADCSimpleWindowAlgorithm::construct_ta() const
{
  TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:ADCSW] I am constructing a trigger activity!";
  //TLOG_DEBUG(TRACE_NAME) << m_current_window;

  const TriggerPrimitive& last_tp = m_current_window.tp_list.back();
  uint64_t ch_min{last_tp.channel}, ch_max{last_tp.channel};
  uint64_t time_min{last_tp.time_start}, time_max{last_tp.time_start + last_tp.samples_over_threshold * k_sample_to_dts_ticks};

  uint64_t adc_peak{last_tp.adc_peak};
  uint64_t ch_peak{last_tp.channel};
  timestamp_t time_peak{last_tp.time_start + last_tp.samples_to_peak * k_sample_to_dts_ticks};


  std::vector<TriggerPrimitive> tp_list;
  tp_list.reserve(m_current_window.tp_list.size());


  // Copy the queue into the vector
  // And compute TA parameters
  for( const auto& tp : m_current_window.tp_list ) {
    
    ch_min = std::min(ch_min, tp.channel);
    ch_max = std::max(ch_max, tp.channel);
    time_min = std::min(time_min, tp.time_start);
    time_max = std::max(time_max, tp.time_start + tp.samples_over_threshold * k_sample_to_dts_ticks); // FIXME: Replace the hard-coded SOT to TOT scaling.
    if (tp.adc_peak > adc_peak) {
      adc_peak = tp.adc_peak;
      ch_peak = tp.channel;
      time_peak = tp.time_start + tp.samples_to_peak * k_sample_to_dts_ticks; // FIXME: Replace the hard-coded STP to `time_peak` conversion.
    }

    tp_list.push_back(tp);
  }

  TriggerActivity ta;

  ta.time_start = time_min;
  ta.time_end = time_max; 
  ta.time_peak = time_peak;
  ta.time_activity = time_peak;
  ta.channel_start = ch_min;
  ta.channel_end = ch_max;
  ta.channel_peak = ch_peak;
  ta.adc_integral = m_current_window.adc_integral;
  ta.adc_peak = adc_peak;
  ta.detid = last_tp.detid;
  ta.type = TriggerActivity::Type::kTPC;
  ta.algorithm = TriggerActivity::Algorithm::kADCSimpleWindow;
  ta.inputs.swap(tp_list);
  return ta;
}


// Register algo in TA Factory
REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TAMakerADCSimpleWindowAlgorithm)

}
