/**
 * @file TriggerDecisionMaker.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERDECISIONMAKER_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERDECISIONMAKER_HPP_

#include "triggeralgs/Logging.hpp"
#include "triggeralgs/TriggerCandidate.hpp"
#include "triggeralgs/TriggerDecision.hpp"

#include <nlohmann/json.hpp>
#include <vector>
#include <atomic>
#include <chrono>

namespace triggeralgs {

class TriggerDecisionMaker
{
public:
  virtual ~TriggerDecisionMaker() = default;
  virtual void operator()(const TriggerCandidate& input_tc, std::vector<TriggerDecision>& output_tds) = 0;
  virtual void flush(std::vector<TriggerDecision>&) {}
  virtual void configure(const nlohmann::json&) {}

  std::atomic<uint64_t> m_data_vs_system_time = 0; 

};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERDECISIONMAKER_HPP_
