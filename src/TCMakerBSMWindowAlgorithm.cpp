/**
 * @file TCMakerBSMWindowAlgorithm.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/BSMWindow/TCMakerBSMWindowAlgorithm.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TCMakerBSMWindowAlgorithm"

#include <vector>

using namespace triggeralgs;

using Logging::TLVL_DEBUG_LOW;

void TCMakerBSMWindowAlgorithm::process(const TriggerActivity& activity, std::vector<TriggerCandidate>& cand)
//TCMakerBSMWindowAlgorithm::operator()(const TriggerActivity& activity, std::vector<TriggerCandidate>& cand)
{ 

  // For now, if there is any single activity from any one detector element, emit
  // a trigger candidate.
  m_activity_count++;
  std::vector<TriggerActivity::TriggerActivityData> ta_list = {static_cast<TriggerActivity::TriggerActivityData>(activity)};

  TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TCM:ADCSW] Emitting an "
                             << dunedaq::trgdataformats::get_trigger_candidate_type_names()[m_tc_type]
                             << " TriggerCandidate with AEAnomalyWindow algorithm" << (m_activity_count-1);

  TriggerCandidate tc;
  tc.time_start = activity.time_start; 
  tc.time_end = activity.time_end;  
  tc.time_candidate = activity.time_activity;
  tc.detid = activity.detid;
  tc.type = m_tc_type;
  //tc.algorithm = TriggerCandidate::Algorithm::kAEAnomalyWindow;
  tc.algorithm = TriggerCandidate::Algorithm::kUnknown;

  tc.inputs = ta_list;

  cand.push_back(tc);

}

void
TCMakerBSMWindowAlgorithm::configure(const nlohmann::json &config)
{
  TriggerCandidateMaker::configure(config);
  /*
  // Don't configure if no configuration object
  if (!config.is_object())
    return;

  // Set the TC name
  if (config.contains("tc_type_name")){
    m_tc_type = static_cast<triggeralgs::TriggerCandidate::Type>(
         dunedaq::trgdataformats::string_to_fragment_type_value(config["tc_type_name"]));

    // Set unknown to the default kAEAnomalyWindow
    if (m_tc_type == triggeralgs::TriggerCandidate::Type::kUnknown) {
      //m_tc_type = TriggerCandidate::Type::kAEAnomalyWindow;
      m_tc_type = TriggerCandidate::Type::kUnknown;
    }

    TLOG() << "[TCM:ADCSW]: setting output TC type to "
           << dunedaq::trgdataformats::get_trigger_candidate_type_names()[m_tc_type];
  }
  */
}

REGISTER_TRIGGER_CANDIDATE_MAKER(TRACE_NAME, TCMakerBSMWindowAlgorithm)
