/**
 * @file TriggerActivity.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITY_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITY_HPP_

#include "triggeralgs/Types.hpp"
#include "triggeralgs/TriggerPrimitive.hpp"
#include <cstdint>
#include <vector>

namespace triggeralgs {


struct TriggerActivity
{
  enum class Type {
    kUnknown = 0,
    kTPC = 1,
    kPDS = 2,
  };

  enum class Algorithm {
    kUnknown = 0,
    kSupernova = 1,
    kPrescale = 2
  };

  timestamp_t time_start = INVALID_TIMESTAMP;
  timestamp_t time_end = INVALID_TIMESTAMP;
  timestamp_t time_peak = INVALID_TIMESTAMP;
  timestamp_t time_activity = INVALID_TIMESTAMP;
  channel_t channel_start = INVALID_CHANNEL; // NOLINT(build/unsigned)
  channel_t channel_end = INVALID_CHANNEL;   // NOLINT(build/unsigned)
  channel_t channel_peak = INVALID_CHANNEL;  // NOLINT(build/unsigned)
  uint64_t adc_integral =  0;  // NOLINT(build/unsigned)
  uint16_t adc_peak = 0;      // NOLINT(build/unsigned)
  detid_t detid = INVALID_DETID;         // NOLINT(build/unsigned)
  Type type = Type::kUnknown;          // NOLINT(build/unsigned)
  Algorithm algorithm = Algorithm::kUnknown;     // NOLINT(build/unsigned)
  version_t version = INVALID_VERSION;       // NOLINT(build/unsigned)

  std::vector<TriggerPrimitive> tp_list;
};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITY_HPP_
