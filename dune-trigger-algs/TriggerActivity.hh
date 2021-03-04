#pragma once
#include <cstdint>
#include <vector>
#include "dune-trigger-algs/TriggerPrimitive.hh"

namespace triggeralgs {
  struct TriggerActivity {
    int64_t  time_start    = {0};
    int64_t  time_end      = {0};
    int64_t  time_peak     = {0};
    int64_t  time_activity = {0};
    uint16_t channel_start = {0};
    uint16_t channel_end   = {0};
    uint16_t channel_peak  = {0};
    uint64_t adc_integral  = {0};
    uint16_t adc_peak      = {0};
    uint16_t detid         = {0};
    uint32_t type          = {0};
    uint32_t algorithm     = {0};
    uint16_t version       = {0};

    std::vector<TriggerPrimitive> tp_list;
  };
    
}
