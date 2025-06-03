#ifndef TRIGGERALGS_BINNEDWINDOW_HPP_
#define TRIGGERALGS_BINNEDWINDOW_HPP_

#include "triggeralgs/Types.hpp"
#include "triggeralgs/BSMWindow/WindowBin.hpp"

#include <ostream>
#include <vector>
#include <numeric>

namespace triggeralgs {

class BinnedWindow {
public:
  void addbin(WindowBin const &input_bin);
  
  void resetwindow(WindowBin const &input_bin);

  void movebin(WindowBin const &input_bin);

  float sumadc() const;

  int bincount() const;

  std::vector<std::vector<TriggerPrimitive>> getTPbins() const;

  std::vector<TriggerPrimitive> flattenTPbins() const;

  timestamp_t window_time_start;
  std::vector<WindowBin> tp_window_bins;
  std::vector<float> ae_input;
};

}

#endif
