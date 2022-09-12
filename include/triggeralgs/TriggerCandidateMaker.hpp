/**
 * @file TriggerCandidateMaker.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_

#include "triggeralgs/TriggerActivity.hpp"
#include "triggeralgs/TriggerCandidate.hpp"
#include "triggeralgs/Types.hpp"

#include <nlohmann/json.hpp>
#include <vector>

namespace triggeralgs {

class TriggerCandidateMaker
{
public:
  virtual ~TriggerCandidateMaker() = default;
  virtual void operator()(const TriggerActivity& input_ta, std::vector<TriggerCandidate>& output_tc) = 0;
  virtual void flush(timestamp_t /* until */, std::vector<TriggerCandidate>& /* output_tc */) {}
  virtual void configure(const nlohmann::json&) {}
};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_
