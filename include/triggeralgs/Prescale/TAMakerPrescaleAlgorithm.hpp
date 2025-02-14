/**
 * @file TAMakerPrescaleAlgorithm.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_PRESCALE_TRIGGERACTIVITYMAKERPRESCALE_HPP_
#define TRIGGERALGS_PRESCALE_TRIGGERACTIVITYMAKERPRESCALE_HPP_

#include "triggeralgs/TriggerActivityFactory.hpp"

#include <vector>

namespace triggeralgs {
class TAMakerPrescaleAlgorithm : public TriggerActivityMaker
{

public:
  void process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta);
  
  void configure(const nlohmann::json &config);
  
private:  
};
} // namespace triggeralgs

#endif // TRIGGERALGS_PRESCALE_TRIGGERACTIVITYMAKERPRESCALE_HPP_
