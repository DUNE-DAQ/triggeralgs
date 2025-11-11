/**
 * @file TriggerActivity.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITY_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITY_HPP_

#include "trgdataformats/TriggerActivityData.hpp"
#include "triggeralgs/TriggerPrimitive.hpp"

#include <vector>

namespace triggeralgs {

struct TriggerActivity : public dunedaq::trgdataformats::TriggerActivityData
{
  TriggerActivity() = default;
  TriggerActivity(const TriggerActivity&) = default;
  TriggerActivity(TriggerActivity&&) = default;
  TriggerActivity& operator=(const TriggerActivity&) = default;
  TriggerActivity& operator=(TriggerActivity&&) = default;
  ~TriggerActivity() = default;

  TriggerActivity(dunedaq::trgdataformats::TriggerActivityData&& data)
      : dunedaq::trgdataformats::TriggerActivityData(std::move(data)) {}
  TriggerActivity(const dunedaq::trgdataformats::TriggerActivityData &data)
      : dunedaq::trgdataformats::TriggerActivityData(data) {}

  std::vector<TriggerPrimitive> inputs;
};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITY_HPP_
