#ifndef TRIGGERALGS_BSMWINDOW_HPP_
#define TRIGGERALGS_BSMWINDOW_HPP_

#include "triggeralgs/TriggerPrimitive.hpp"
#include "triggeralgs/Types.hpp"
#include "triggeralgs/BSMWindow/models/treelite_compmodel_classifier_xgboost/treelitemodel.h"

#include <ostream>
#include <vector>
#include <numeric>

namespace triggeralgs {

class BSMWindow {
  public:
    bool is_empty() const;
    void add(TriggerPrimitive const &input_tp);
    void clear();
    void move(TriggerPrimitive const &input_tp, timestamp_t const &window_length);
    void reset(TriggerPrimitive const &input_tp);

    void bin_window(std::vector<float> &input, timestamp_t &bin_width,int &num_bins);
    void bin_entry_window(std::vector<Entry> &input, timestamp_t &bin_width, int &num_bins);
    void fill_entry_window(std::vector<Entry> &entry_input, std::vector<float> &input);

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
