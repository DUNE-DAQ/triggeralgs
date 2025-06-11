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

void
TAMakerBSMWindowAlgorithm::process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta)
{
  
  // The first time operator is called, reset
  // window object.
  if(m_current_window.is_empty()){
    m_current_window.reset(input_tp);
    m_last_pred_time = input_tp.time_start;
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
  else if ((m_current_window.time_start - m_last_pred_time) > m_bin_length && // check enough time has passed since last window
      m_current_window.tp_list.size() > 20 && // need enough TPs in window to bother
      m_current_window.adc_integral > m_adc_threshold && // set a low minimum threshold for the ADC integral sum
      //m_current_window.mean_sadc() < 50000 && // can we do something with the mean SADC?
      compute_treelite_classification()) // XGBoost classifier
  {
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
      if (int_bdt_threshold <= 100) m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.01);
      else if (int_bdt_threshold <= 1000) m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.001);
      else if (int_bdt_threshold <= 10000) m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.0001);
      else m_bdt_threshold = static_cast<float>(int_bdt_threshold * 0.01);
    }
    if (config.contains("alg_type")) m_algtype = config["alg_type"];
  }
  else{
    TLOG_DEBUG(TLVL_IMPORTANT) << "[TAM:ADCSW] The DEFAULT values of window_length and adc_threshold are being used.";
  }
  TLOG_DEBUG(TLVL_IMPORTANT) << "[TAM:ADCSW] If the total ADC of trigger primitives with times within a "
                         << m_bin_length << " tick time window is above " << m_adc_threshold << " counts, a trigger will be issued.";
  std::cout << "bin length is " << m_bin_length << " for a window of " << nbins << " bins. ADC threshold across window set to " << m_adc_threshold << std::endl;

  nbatch_iterator = 0;

  std::cout << "Batch size = " << nbatch << std::endl;

  flat_batched_inputs.resize(nbatch * nbins);
  
  if (m_algtype == 0) {
    std::cout << "Using ADCSimpleWindow equivelent algorithm." << std::endl;
  }

  else if (m_algtype == 1) { // Treelite for inference Algorithm
    std::cout << "Using XGBoost model with Treelite GTIL inference window algorithm." << std::endl;  
    std::string xgboost_model_path = "/exp/dune/app/users/chasnip/CERN_Fellowship/DUNE_DAQ_Development/sourcecode/triggeralgs/include/triggeralgs/BSMWindow/models/nu_cosmicoverlay_classifier_xgboost.json";
    m_treelite_model_interface = std::make_unique<TreeliteModelInterface>(xgboost_model_path.c_str(), nbatch);
    m_treelite_model_interface->ModelWarmUp(flat_batched_inputs.data());
  }

  else if (m_algtype == 2) {
    std::cout << "Using XGBoost model with compiled Treelite inference window algorithm." << std::endl;
    const size_t num_feature = get_num_feature();
    flat_batched_Entries.clear();
    for (size_t i = 0; i < num_feature; ++i) {
      union Entry zero;
      zero.fvalue = 0.0;
      flat_batched_Entries.emplace_back(zero);
    }
    m_compiled_model_interface = std::make_unique<CompiledModelInterface>(nbatch);
    //m_compiled_model_interface->ModelWarmUp(flat_batched_Entries.data());
  }

  else {
    std::cerr << "[ERROR] unrecognised algorithm number " << m_algtype << ". Must be 0, 1 or 2\n";
    exit(1);
}

TAMakerBSMWindowAlgorithm::~TAMakerBSMWindowAlgorithm() {
  // Treelite smart ptr should clean itself up
}

TriggerActivity
TAMakerBSMWindowAlgorithm::construct_ta() const
{
  TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TAM:ADCSW] I am constructing a trigger activity!";

  //TriggerPrimitive latest_tp_in_window = m_current_bin.tp_list.back();
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
  //ta.inputs = m_current_window.flattenTPbins();
  ta.inputs = m_current_window.tp_list;
  return ta;
}

bool TAMakerBSMWindowAlgorithm::compute_treelite_classification() {

  m_last_pred_time = m_current_window.time_start;
  m_current_window.bin_window(flat_batched_inputs, m_bin_length, nbins);
  
  if (m_algtype == 1) {
    
    //m_current_window.bin_window(flat_batched_inputs, m_bin_length, nbins);
    float result[m_treelite_model_interface->GetShapeElement(0)];
    auto start_inference = std::chrono::high_resolution_clock::now();
    m_treelite_model_interface->Predict(flat_batched_inputs.data(), result);
    auto end_inference = std::chrono::high_resolution_clock::now();
    auto duration_inference = std::chrono::duration_cast<std::chrono::nanoseconds>(end_inference - start_inference);
    std::cout << ">>> Inference time: " << duration_inference.count() << std::endl;

    return m_treelite_model_interface->Classify(result, m_bdt_threshold);
  
  } else if (m_algtype == 2) {
    
    //m_current_window.bin_entry_window(flat_batched_Entries, m_bin_length, nbins);
    //auto start_inference = std::chrono::high_resolution_clock::now();
    m_current_window.fill_entry_window(flat_batched_Entries, flat_batched_inputs); 
    /*
    std::cout << "Input of size " << flat_batched_Entries.size() << ": ";
    for (const auto &in : flat_batched_Entries) {
      std::cout << in.fvalue << ", ";
    }
    std::cout << "\n";
    */
    float result[nbatch];
    //auto start_inference = std::chrono::high_resolution_clock::now();
    m_compiled_model_interface->Predict(flat_batched_Entries.data(), result);
    //auto end_inference = std::chrono::high_resolution_clock::now();
    //auto duration_inference = std::chrono::duration_cast<std::chrono::nanoseconds>(end_inference - start_inference);
    //std::cout << ">>> Inference time: " << duration_inference.count() << std::endl;
    return m_compiled_model_interface->Classify(result, m_bdt_threshold);

  } else {
    std::cerr << "[ERROR] Algorithm choice is not configured : " << m_algtype << "\n";
    exit(1);
    return false;
  }
}

// Register algo in TA Factory
REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TAMakerBSMWindowAlgorithm)
