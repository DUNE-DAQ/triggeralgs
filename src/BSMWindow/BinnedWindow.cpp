#include "triggeralgs/BSMWindow/BinnedWindow.hpp"

namespace triggeralgs {

void BinnedWindow::addbin(WindowBin const &input_bin) {
  tp_window_bins.push_back(input_bin);
  ae_input.push_back(static_cast<float>(input_bin.adc_integral));
}

void BinnedWindow::resetwindow(WindowBin const &input_bin) {
        window_time_start = input_bin.time_start;
        tp_window_bins.clear();
        ae_input.clear();
}

/*void BinnedWindow::movebin(WindowBin const &input_bin) {
  // Add the next bin
  // All bins of equal length in time - so just pop out the front bin of TPs
  tp_window_bins.erase(tp_window_bins.begin());
  tp_window_bins.push_back(input_bin);

  ae_input.erase(ae_input.begin());
  ae_input.push_back(input_bin.adc_integral);
}*/
void BinnedWindow::movebin(WindowBin const &input_bin, timestamp_t const& window_length) {
  // Add the next bin
  // Find all the time bins that need to be removed 
  // if the window is to maintain the same time length
  uint32_t n_bins_to_erase = 0;
  for (auto &tp_bin : tp_window_bins) {
    if (!(input_bin.time_start - tp_bin.time_start < window_length)) {
      n_bins_to_erase++;
    }
  }

  tp_window_bins.erase(tp_window_bins.begin(), tp_window_bins.begin() + n_bins_to_erase);
  ae_input.erase(ae_input.begin(), ae_input.begin() + n_bins_to_erase);

  if (tp_window_bins.size() != 0) {
    auto binstart_diff = input_bin.time_start - tp_window_bins.back().time_start;
    int bins_to_add = static_cast<int>(binstart_diff / 1000) - 1;
    int bin_count = 0;
    while (bin_count < bins_to_add && this->bincount() < 20) {
      ++bin_count;
      //std::cout << "Adding empty bin " << bin_count << " at start time " << m_current_bin.time_start + bin_count * m_bin_length << "\n";
      WindowBin m_zero_bin;
      m_zero_bin.initbinempty(tp_window_bins.back().time_start + bin_count * 1000);
      this->addbin(m_zero_bin);
    }
    this->addbin(input_bin);
  } else {
    resetwindow(input_bin);
  }

}

float BinnedWindow::sumadc() const {
  float sum = std::accumulate(ae_input.begin(), ae_input.end(), 0);
  return sum;
}

int BinnedWindow::bincount() const {
  return (int)ae_input.size();
}

std::vector<std::vector<TriggerPrimitive>> BinnedWindow::getTPbins() const {
  // Place the TPs from each bin into a vector  
  std::vector<std::vector<TriggerPrimitive>> ret;
  for (const auto &win_bin : tp_window_bins) {
    ret.push_back(win_bin.tp_list);
  }

  return ret;
}

std::vector<TriggerPrimitive> BinnedWindow::flattenTPbins() const {

  auto tps_by_bin = getTPbins();

  std::vector<TriggerPrimitive> ret;
  for (const auto &tps : tps_by_bin) {
    for (const auto &tp : tps) {
      ret.push_back(tp);
    }
  }

  return ret;
}

} // namespace triggeralgs
