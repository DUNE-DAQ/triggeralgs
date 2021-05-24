/**
 * @file TriggerActivityMaker.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITYMAKER_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITYMAKER_HPP_

#include "triggeralgs/TriggerActivity.hpp"
#include "triggeralgs/TriggerPrimitive.hpp"

#include <string>
#include <vector>

namespace triggeralgs {

class TriggerActivityMaker
{
public:
  virtual void operator()(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta) = 0;
  virtual void flush(std::vector<TriggerActivity>&) {}
};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITYMAKER_HPP_