/**
 * @file TriggerCandidateMakerPrescale.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/Prescale/TriggerCandidateMakerPrescale.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TriggerCandidateMakerPrescalePlugin"

#include <vector>

using namespace triggeralgs;

using Logging::TLVL_DEBUG_LOW;
using Logging::TLVL_IMPORTANT;

void
TriggerCandidateMakerPrescale::operator()(const TriggerActivity& activity, std::vector<TriggerCandidate>& cand)
{ 
  if ((m_activity_count++) % m_prescale == 0)
  {
    TLOG_DEBUG(TLVL_DEBUG_LOW) << "[TCM:Pr] Emitting prescaled TriggerCandidate " << (m_activity_count-1);

    std::vector<TriggerActivity::TriggerActivityData> ta_list;
    ta_list.push_back(static_cast<TriggerActivity::TriggerActivityData>(activity));
    
    TriggerCandidate tc;
    tc.time_start = activity.time_start - m_readout_window_ticks_before;
    tc.time_end = activity.time_end + m_readout_window_ticks_after;
    tc.time_candidate = activity.time_start;
    tc.detid = activity.detid;
    tc.type = TriggerCandidate::Type::kPrescale;
    tc.algorithm = TriggerCandidate::Algorithm::kPrescale;

    tc.inputs = ta_list;

    using namespace std::chrono;

    // Update OpMon Variable(s)
    uint64_t system_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    uint64_t data_time = activity.time_start*16e-6;       // Convert 62.5 MHz ticks to ms    
    m_data_vs_system_time.store(data_time - system_time); // Store the difference for OpMon

    cand.push_back(tc);
  }
}

void
TriggerCandidateMakerPrescale::configure(const nlohmann::json &config)
{
  if (config.is_object() && config.contains("prescale"))
  {
    m_prescale = config["prescale"];
    if (config.contains("readout_window_ticks_before"))
      m_readout_window_ticks_before = config["readout_window_ticks_before"];
    if (config.contains("readout_window_ticks_after"))
      m_readout_window_ticks_after = config["readout_window_ticks_after"];

  }
  TLOG_DEBUG(TLVL_IMPORTANT) << "[TCM:pr] Using candidate prescale " << m_prescale;
}

REGISTER_TRIGGER_CANDIDATE_MAKER(TRACE_NAME, TriggerCandidateMakerPrescale)
