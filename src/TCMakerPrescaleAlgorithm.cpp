/**
 * @file TCMakerPrescaleAlgorithm.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/Prescale/TCMakerPrescaleAlgorithm.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TCMakerPrescaleAlgorithm"

#include <vector>

using namespace triggeralgs;

void
TCMakerPrescaleAlgorithm::process(const TriggerActivity& activity, std::vector<TriggerCandidate>& cand)
{ 
  std::vector<TriggerActivity::TriggerActivityData> ta_list;
  ta_list.push_back(static_cast<TriggerActivity::TriggerActivityData>(activity));
  
  TriggerCandidate tc;
  tc.time_start = activity.time_start;
  tc.time_end = activity.time_end;
  tc.time_candidate = activity.time_start;
  tc.detid = activity.detid;
  tc.type = m_tc_type_out;
  tc.algorithm = TriggerCandidate::Algorithm::kPrescale;

  tc.inputs = ta_list;

  using namespace std::chrono;

  // Update OpMon Variable(s)
  uint64_t system_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  uint64_t data_time = activity.time_start*16e-6;       // Convert 62.5 MHz ticks to ms    
  m_data_vs_system_time.store(data_time - system_time); // Store the difference for OpMon

  cand.push_back(tc);
}

void
TCMakerPrescaleAlgorithm::configure(const nlohmann::json &config)
{
  TriggerCandidateMaker::configure(config);
}

REGISTER_TRIGGER_CANDIDATE_MAKER(TRACE_NAME, TCMakerPrescaleAlgorithm)
