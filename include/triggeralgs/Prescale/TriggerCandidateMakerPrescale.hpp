/**
 * @file TriggerCandidateMakerPrescale.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_SRC_TRIGGERALGS_SUPERNOVA_TRIGGERCANDIDATEMAKERPRESCALE_HPP_
#define TRIGGERALGS_SRC_TRIGGERALGS_SUPERNOVA_TRIGGERCANDIDATEMAKERPRESCALE_HPP_

#include "triggeralgs/TriggerCandidateMaker.hpp"

#include <algorithm>
#include <atomic>
#include <limits>
#include <vector>

namespace triggeralgs {
class TriggerCandidateMakerPrescale : public TriggerCandidateMaker
{

public:
  /// The function that gets call when there is a new activity
  void operator()(const TriggerActivity&, std::vector<TriggerCandidate>&);
  
  void configure(const nlohmann::json &config);
  
private:

  uint64_t m_activity_count = 0;    // NOLINT(build/unsigned)
  uint64_t m_prescale = 1;          // NOLINT(build/unsigned)
  
};

} // namespace triggeralgs

#endif // TRIGGERALGS_SRC_TRIGGERALGS_SUPERNOVA_TRIGGERCANDIDATEMAKERPRESCALE_HPP_
