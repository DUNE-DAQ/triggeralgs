#ifndef TRIGGERALGS_BSMWINDOW_HPP_
#define TRIGGERALGS_BSMWINDOW_HPP_

#include "triggeralgs/TriggerPrimitive.hpp"
#include "triggeralgs/Types.hpp"
#include "triggeralgs/BSMWindow/treelitemodel.hpp"
#include "triggeralgs/BSMWindow/PDVDEffectiveChannelMap.hpp"

#include <ostream>
#include <vector>
#include <numeric>

namespace triggeralgs {

// Class to hold data of TPs within a window in time.
// Functions to move the window along in time by removing
// old TPs and add in newer ones
// Function to bin the TPs in the window as a function of
// channel and time
class BSMWindow {
  public:
    bool is_empty() const;
    void add(TriggerPrimitive const &input_tp);
    void clear();
    void move(TriggerPrimitive const &input_tp, timestamp_t const &window_length);
    void reset(TriggerPrimitive const &input_tp);

    // Bins the TPs as a function of channel and time
    // If running in PD-VD then effective channel ID is used
    void bin_window(std::vector<float> &input, timestamp_t time_bin_width, channel_t chan_bin_width, 
                    int num_time_bins, int num_chan_bins, channel_t first_channel,
                    std::unique_ptr<PDVDEffectiveChannelMap> const &effective_channel_mapper, bool use_pdvd_map);

    void fill_entry_window(std::vector<Entry> &entry_input, std::vector<float> &input);

    // Calculate average properties of TPs in a time window
    float mean_sadc();
    float mean_adc_peak();
    float mean_tot();

    friend std::ostream& operator<<(std::ostream& os, const BSMWindow& window);

    timestamp_t time_start;
    uint32_t adc_integral;
    uint64_t adc_peak_sum;
    uint64_t tot_sum;
    std::vector<TriggerPrimitive> tp_list;
  };
}
#endif // TRIGGERALGS_BSMWINDOW_HPP_
