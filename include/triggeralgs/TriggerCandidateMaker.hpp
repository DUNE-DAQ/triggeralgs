/**
 * @file TriggerCandidateMaker.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_

#include "triggeralgs/Logging.hpp"
#include "triggeralgs/TriggerActivity.hpp"
#include "triggeralgs/TriggerCandidate.hpp"
#include "triggeralgs/Types.hpp"

#include <nlohmann/json.hpp>
#include <vector>
#include <atomic>
#include <chrono>

namespace triggeralgs {

class TriggerCandidateMaker
{
public:
  virtual ~TriggerCandidateMaker() = default;
  virtual void operator()(const TriggerActivity& input_ta, std::vector<TriggerCandidate>& output_tc) = 0;
  virtual void flush(timestamp_t /* until */, std::vector<TriggerCandidate>& /* output_tc */) {}
  virtual void configure(const nlohmann::json&) {}

  std::atomic<uint64_t> m_data_vs_system_time = 0;
  std::atomic<uint64_t> m_initial_offset = 0;  
};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_
