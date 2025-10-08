/**
 * @file TCMakerADCSimpleWindowAlgorithm.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/ADCSimpleWindow/TCMakerADCSimpleWindowAlgorithm.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TCMakerADCSimpleWindowAlgorithm"

#include <vector>

using namespace triggeralgs;

void
TCMakerADCSimpleWindowAlgorithm::process(const TriggerActivity& activity, std::vector<TriggerCandidate>& cand)
{ 


  
  // Accumulate TAs with the same start time
  // FIXME: accumulation relies on the "next" event to release the accumulated values.
  if (m_ta_list.empty() or activity.time_start == m_ta_list.front().time_start) {
    m_ta_list.push_back(activity);
    return;
  }


  if ( m_ta_list.front().time_start != activity.time_start) {

    const auto& ta_first = m_ta_list.front();
    timestamp_t time_start = ta_first.time_start;
    timestamp_t time_end = ta_first.time_end;


    std::vector<TriggerActivity::TriggerActivityData> ta_list;
    for( const auto& ta : m_ta_list) {
      time_end = std::max(ta_first.time_end, time_end);
      ta_list.push_back(static_cast<TriggerActivity::TriggerActivityData>(ta));
    }

    TriggerCandidate tc;
    tc.time_start = time_start; 
    tc.time_end = time_end;  
    tc.time_candidate = ta_first.time_activity;
    tc.detid = ta_first.detid;
    tc.type = m_tc_type_out; 
    tc.algorithm = TriggerCandidate::Algorithm::kADCSimpleWindow;

    tc.inputs = ta_list;
    cand.push_back(tc);
    

    m_ta_list.clear();
    m_ta_list.push_back(activity);
  }



  // // For now, if there is any single activity from any one detector element, emit
  // // a trigger candidate.
  // std::vector<TriggerActivity::TriggerActivityData> ta_list = {static_cast<TriggerActivity::TriggerActivityData>(activity)};

  // TriggerCandidate tc;
  // tc.time_start = activity.time_start; 
  // tc.time_end = activity.time_end;  
  // tc.time_candidate = activity.time_activity;
  // tc.detid = activity.detid;
  // tc.type = m_tc_type_out; 
  // tc.algorithm = TriggerCandidate::Algorithm::kADCSimpleWindow;

  // tc.inputs = ta_list;

  // cand.push_back(tc);

}

void
TCMakerADCSimpleWindowAlgorithm::configure(const nlohmann::json &config)
{
  TriggerCandidateMaker::configure(config);

  m_ta_list.clear();
}

REGISTER_TRIGGER_CANDIDATE_MAKER(TRACE_NAME, TCMakerADCSimpleWindowAlgorithm)
