/**
 * @file TAMakerBSMWindowAlgorithm.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/BSMWindow/TAMakerBSMWindowAlgorithm.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TAMakerBSMWindowAlgorithm"

#include <vector>
#include <chrono>

using namespace triggeralgs;
using Logging::TLVL_DEBUG_ALL;
using Logging::TLVL_DEBUG_HIGH;
using Logging::TLVL_DEBUG_LOW;
using Logging::TLVL_IMPORTANT;

void TAMakerBSMWindowAlgorithm::process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta)
{
  // The first time operator is called, reset
  // window object.
  if(m_current_bin.is_empty()){
    m_current_bin.reset(input_tp);
    m_current_window.resetwindow(m_current_bin);
    m_primitive_count++;
    return;
  }

  // If the difference between the current TP's start time and the start of the bin
  // is less than the specified bin width, add the TP to the bin.
  if((input_tp.time_start - m_current_bin.time_start) < m_bin_length){
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:ADCSW] Bin not yet complete, adding the input_tp to the bin.";
    //std::cout << "[TAM:ADCSW] Bin not yet complete, adding the input_tp to the bin.\n";
    //std::cout << "TP time : " << input_tp.time_start << ", TP ADC : " << input_tp.adc_integral << "\n";
    auto difference = input_tp.time_start - m_current_bin.time_start;
    //std::cout << "bin length is " << m_bin_length << ", but difference is " << difference << "\n";
    m_current_bin.add(input_tp);
  } 
  // If the window bins have not been all filled yet, add another bin
  else if (m_current_window.bincount() < nbins) {
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:ADCSW] Window not yet complete, adding bin to the window.";
    //std::cout << "[TAM:ADCSW] Window not yet complete, adding bin to the window.\n";
    m_current_window.addbin(m_current_bin);
    // Bin added - remember to reset the bin to start again
    m_current_bin.reset(input_tp);
  }
  // If the addition of the current TP to the window would make it longer
  // than the specified window length, don't add it but check whether the sum of all adc in
  // the existing window is above the specified threshold. If it is, make a TA and start 
  // a fresh window with the current TP.
  // This logic will be replaced with AE calculation
  else if (m_algtype == 0 && m_current_window.sumadc() > m_adc_threshold){
    TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:ADCSW] ADC integral in window is greater than specified threshold.";
    std::cout << "[TAM:ADCSW] ADC integral in window is greater than specified threshold." << std::endl;
    output_ta.push_back(construct_ta());
    TLOG_DEBUG(TLVL_DEBUG_HIGH) << "[TAM:ADCSW] Resetting window with input_tp.";
    std::cout << "[TAM:ADCSW] Resetting window with input_tp." << std::endl;
    m_current_bin.reset(input_tp);
    m_current_window.resetwindow(m_current_bin);
    std::cout << "Constructed TA with AE Window alg!" << std::endl;
  }

  else if (m_algtype == 1 && nbatch_iterator < nbatch) {
    //std::cout << "filling batch with current input: ";
    for (int i = 0; i < nbins; i++) {
      //std::cout << m_current_window.ae_input.at(i) << ", ";
      flat_batched_inputs.at(i + (nbatch_iterator * nbins)) = m_current_window.ae_input.at(i);
    }
    //std::cout << "\n";
    //std::cout << m_current_bin << "\n";
    m_current_window.movebin(m_current_bin); 
    m_current_bin.reset(input_tp);
    nbatch_iterator++;
  } 
  else if (m_algtype == 1 && nbatch_iterator == nbatch && compute_treelite_classification()) {
    output_ta.push_back(construct_ta());
    m_current_bin.reset(input_tp);
    m_current_window.resetwindow(m_current_bin);
    nbatch_iterator = 0;
  }

  // If it is not, move the window along by removing the front bin and adding a new one to the back
  else {
    TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:ADCSW] Window is at required length but threshold not met, shifting window along by 1 window bin.";
    m_current_window.movebin(m_current_bin);
    m_current_bin.reset(input_tp);
    nbatch_iterator = 0;
  }
  
  //TLOG_DEBUG(TLVL_DEBUG_ALL) << "[TAM:ADCSW] " << m_current_window;

  m_primitive_count++;

  return;
}

void
TAMakerBSMWindowAlgorithm::configure(const nlohmann::json &config)
{
  //FIXME use some schema here
  if (config.is_object()){
    if (config.contains("bin_length")) m_bin_length = config["bin_length"];
    if (config.contains("adc_threshold")) m_adc_threshold = config["adc_threshold"];
    if (config.contains("batch_size")) nbatch = config["batch_size"];
    if (config.contains("window_length")) {
      m_window_length = config["window_length"];
      std::cout << "window length = " << m_window_length << " and bin length = " << m_bin_length << std::endl;
      nbins = static_cast<int>(m_window_length / m_bin_length);
    }
    if (config.contains("bdt_threshold")) {
      uint64_t int_bdt_threshold = config["bdt_threshold"];
      m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.01);
    }
    if (config.contains("alg_type")) m_algtype = config["alg_type"];
  }
  else{
    TLOG_DEBUG(TLVL_IMPORTANT) << "[TAM:ADCSW] The DEFAULT values of window_length and adc_threshold are being used.";
  }
  TLOG_DEBUG(TLVL_IMPORTANT) << "[TAM:ADCSW] If the total ADC of trigger primitives with times within a "
                         << m_bin_length << " tick time window is above " << m_adc_threshold << " counts, a trigger will be issued.";
  std::cout << "bin length is " << m_bin_length << " for a window of " << nbins << " bins. ADC threshold across window set to " << m_adc_threshold << std::endl;

  if (m_algtype == 0) {
    std::cout << "Using ADCSimpleWindow equivelent algorithm." << std::endl;
  } else if (m_algtype == 1) {
    std::cout << "Using XGBoost model with Treelite inference window algorithm." << std::endl;
  }

  nbatch_iterator = 0;

  std::cout << "Batch size = " << nbatch << std::endl;

  if (m_algtype == 1) { // Treelite for inference Algorithm
    flat_batched_inputs.resize(nbatch * nbins);
    
    std::string xgboost_model_path = "/exp/dune/app/users/chasnip/CERN_Fellowship/DUNE_DAQ_Development/sourcecode/triggeralgs/include/triggeralgs/BSMWindow/models/nu_cosmicoverlay_classifier_xgboost.json";
    m_treelite_model_interface = std::make_unique<TreeliteModelInterface>(xgboost_model_path.c_str(), nbatch);
    m_treelite_model_interface->ModelWarmUp(flat_batched_inputs.data());
  }
}

TAMakerBSMWindowAlgorithm::~TAMakerBSMWindowAlgorithm() {
  // Treelite smart ptr should clean itself up
}

TriggerActivity
TAMakerBSMWindowAlgorithm::construct_ta() const
{
  TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:ADCSW] I am constructing a trigger activity!";

  TriggerPrimitive latest_tp_in_window = m_current_bin.tp_list.back();
  // The time_peak, time_activity, channel_* and adc_peak fields of this TA are irrelevent
  // for the purpose of this trigger alg.
  TriggerActivity ta;
  ta.time_start = m_current_window.window_time_start;
  ta.time_end = latest_tp_in_window.time_start + latest_tp_in_window.samples_over_threshold * 32;
  ta.time_peak = latest_tp_in_window.samples_to_peak * 32 + latest_tp_in_window.time_start;
  ta.time_activity = ta.time_peak;
  ta.channel_start = latest_tp_in_window.channel;
  ta.channel_end = latest_tp_in_window.channel;
  ta.channel_peak = latest_tp_in_window.channel;
  ta.adc_integral = m_current_window.sumadc();
  ta.adc_peak = latest_tp_in_window.adc_peak;
  ta.detid = latest_tp_in_window.detid;
  ta.type = TriggerActivity::Type::kTPC;
  ta.algorithm = TriggerActivity::Algorithm::kUnknown;
  ta.inputs = m_current_window.flattenTPbins();
  return ta;
}

bool TAMakerBSMWindowAlgorithm::compute_treelite_classification() {

  /*
  std::cout << "Input: ";
  for (const auto &in : flat_batched_inputs) {
    std::cout << in << ", ";
  }
  std::cout << "\n";
*/
  float result[m_treelite_model_interface->GetShapeElement(0)];

  m_treelite_model_interface->Predict(flat_batched_inputs.data(), result);

  return m_treelite_model_interface->Classify(result, m_bdt_threshold);
}

// Register algo in TA Factory
REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TAMakerBSMWindowAlgorithm)
