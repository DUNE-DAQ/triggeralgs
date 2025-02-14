/**
 * @file TCMakerPrescaleAlgorithm.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_PRESCALE_TRIGGERCANDIDATEMAKERPRESCALE_HPP_
#define TRIGGERALGS_PRESCALE_TRIGGERCANDIDATEMAKERPRESCALE_HPP_

#include "triggeralgs/TriggerCandidateFactory.hpp"

#include <vector>

namespace triggeralgs {
class TCMakerPrescaleAlgorithm : public TriggerCandidateMaker
{

public:
  /// The function that gets call when there is a new activity
  void process(const TriggerActivity&, std::vector<TriggerCandidate>&);
  
  void configure(const nlohmann::json &config);
  
private:

};

} // namespace triggeralgs

#endif // TRIGGERALGS_PRESCALE_TRIGGERCANDIDATEMAKERPRESCALE_HPP_
