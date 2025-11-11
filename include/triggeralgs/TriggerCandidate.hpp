/**
 * @file TriggerCandidate.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATE_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATE_HPP_

#include "trgdataformats/TriggerActivityData.hpp"
#include "trgdataformats/TriggerCandidateData.hpp"

#include <vector>

namespace triggeralgs {

struct TriggerCandidate : public dunedaq::trgdataformats::TriggerCandidateData
{
  TriggerCandidate() = default;
  TriggerCandidate(const TriggerCandidate&) = default;
  TriggerCandidate(TriggerCandidate&&) = default;
  TriggerCandidate& operator=(const TriggerCandidate&) = default;
  TriggerCandidate& operator=(TriggerCandidate&&) = default;
  ~TriggerCandidate() = default;

  TriggerCandidate(dunedaq::trgdataformats::TriggerCandidateData&& data)
      : dunedaq::trgdataformats::TriggerCandidateData(std::move(data)) {}
  TriggerCandidate(const dunedaq::trgdataformats::TriggerCandidateData &data)
      : dunedaq::trgdataformats::TriggerCandidateData(data) {}

  std::vector<dunedaq::trgdataformats::TriggerActivityData> inputs;
};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATE_HPP_
