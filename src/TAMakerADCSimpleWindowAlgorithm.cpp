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


using namespace triggeralgs;
using Logging::TLVL_DEBUG_ALL;
using Logging::TLVL_DEBUG_HIGH;
using Logging::TLVL_DEBUG_LOW;
using Logging::TLVL_IMPORTANT;

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

  const TriggerPrimitive& latest_tp_in_window = m_current_window.tp_list.back();
  uint64_t ch_min{latest_tp_in_window.channel}, ch_max{latest_tp_in_window.channel};

  std::vector<TriggerPrimitive> tp_list;
  tp_list.reserve(m_current_window.tp_list.size());

  for( const auto& tp : m_current_window.tp_list ) {
    
    ch_min = std::min(ch_min, tp.channel);
    ch_max = std::max(ch_max, tp.channel);

    tp_list.push_back(tp);
  }

  TriggerActivity ta;
  ta.time_start = m_current_window.time_start;
  ta.time_end = latest_tp_in_window.time_start + latest_tp_in_window.samples_over_threshold * 32;  // FIXME: Replace the hard-coded SOT to TOT scaling.
  ta.time_peak = latest_tp_in_window.samples_to_peak * 32 + latest_tp_in_window.time_start;  // FIXME: Replace STP to `time_peak` conversion.
  ta.time_activity = ta.time_peak;
  ta.channel_start = ch_min;
  ta.channel_end = ch_max;
  ta.channel_peak = latest_tp_in_window.channel;
  ta.adc_integral = m_current_window.adc_integral;
  ta.adc_peak = latest_tp_in_window.adc_peak;
  ta.detid = latest_tp_in_window.detid;
  ta.type = TriggerActivity::Type::kTPC;
  ta.algorithm = TriggerActivity::Algorithm::kADCSimpleWindow;
  ta.inputs.swap(tp_list);
  return ta;
}

// Register algo in TA Factory
REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TAMakerADCSimpleWindowAlgorithm)
