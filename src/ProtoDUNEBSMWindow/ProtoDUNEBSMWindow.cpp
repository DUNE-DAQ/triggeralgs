#include "triggeralgs/ProtoDUNEBSMWindow/ProtoDUNEBSMWindow.hpp"

#include <ostream>
#include <vector>
#include <numeric>

namespace triggeralgs {
      
bool ProtoDUNEBSMWindow::is_empty() const{
  return tp_list.empty();
};

void ProtoDUNEBSMWindow::add(TriggerPrimitive const &input_tp){
  // Add the input TP's contribution to the total ADC and add it to
  // the TP list. Also keep running sum of all the samples over threshold
  // and the peak ADC. These are used for samples/peak ratio cut
  adc_integral += input_tp.adc_integral;
  adc_peak_sum += input_tp.adc_peak;
  tot_sum += input_tp.samples_over_threshold;
  tp_list.push_back(input_tp);
};

void ProtoDUNEBSMWindow::clear(){
  tp_list.clear();
};
      
void ProtoDUNEBSMWindow::move(TriggerPrimitive const &input_tp, timestamp_t const &window_length){
  // Find all of the TPs in the window that need to be removed
  // if the input_tp is to be added and the size of the window
  // is to be conserved.
  // Substract those TPs' contribution from the total window ADC.
  uint32_t n_tps_to_erase = 0;
  for(auto tp : tp_list){
    if(!(input_tp.time_start-tp.time_start < window_length)){
      n_tps_to_erase++;
      adc_integral -= tp.adc_integral;
      adc_peak_sum -= tp.adc_peak;
      tot_sum -= tp.samples_over_threshold;
    }
    else break;
  }
  // Erase the TPs from the window.
  tp_list.erase(tp_list.begin(), tp_list.begin()+n_tps_to_erase);
  // Make the window start time the start time of what is now the
  // first TP.
  if(tp_list.size()!=0){
    time_start = tp_list.front().time_start;
    add(input_tp);
  }
  else reset(input_tp);
};

void ProtoDUNEBSMWindow::reset(TriggerPrimitive const &input_tp){
  // Empty the TP list.
  tp_list.clear();
  // Set the start time of the window to be the start time of the 
  // input_tp.
  time_start = input_tp.time_start;
  // Start the total ADC integral.
  adc_integral = input_tp.adc_integral;
  // Add the input TP to the TP list.
  tp_list.push_back(input_tp);
};

void ProtoDUNEBSMWindow::bin_window(
    std::vector<float> &input, 
    int num_time_bins, timestamp_t time_bin_width,
    int num_chan_bins, channel_t chan_bin_width, channel_t first_channel,
    std::unique_ptr<PDVDEffectiveChannelMap> const &effective_channel_mapper,
    bool use_pdvd_map) {

  std::fill(input.begin(), input.end(), 0.0f);

  const float inv_time_bin_width = 1.0f / time_bin_width;
  const float inv_chan_bin_width = 1.0f / chan_bin_width;

  for (const TriggerPrimitive& tp : tp_list) {
    channel_t temp_tp_channel = tp.channel;
    // If in PD-VD convert to effective channel here
    if (effective_channel_mapper && use_pdvd_map) {
      temp_tp_channel = effective_channel_mapper->remapCollectionPlaneChannel(temp_tp_channel);
    }
    size_t time_bin = static_cast<size_t>((tp.time_start - time_start) * inv_time_bin_width);
    size_t channel_bin = static_cast<size_t>((temp_tp_channel - first_channel) * inv_chan_bin_width);
    if (time_bin < num_time_bins && channel_bin < num_chan_bins) {
      size_t index = channel_bin * num_time_bins + time_bin;
      input[index] += tp.adc_integral;
    }
  }
  input[num_time_bins * num_chan_bins] = adc_integral;
};

void ProtoDUNEBSMWindow::fill_entry_window(std::vector<Entry> &entry_input, std::vector<float> &input) {
  for (size_t i = 0; i < input.size(); i++) {
    entry_input[i].fvalue = input[i];
  }
}

float ProtoDUNEBSMWindow::mean_sadc() {
  return static_cast<float>(adc_integral / tp_list.size());;
}
float ProtoDUNEBSMWindow::mean_adc_peak() {
  return static_cast<float>(adc_peak_sum / tp_list.size());
}
float ProtoDUNEBSMWindow::mean_tot() {
  return static_cast<float>(tot_sum / tp_list.size());
}

std::ostream& operator<<(std::ostream& os, const ProtoDUNEBSMWindow& window){
  if(window.is_empty()) os << "Window is empty!\n";
  else{
    os << "Window start: " << window.time_start << ", end: " << window.tp_list.back().time_start;
    os << ". Total of: " << window.adc_integral << " ADC counts with " << window.tp_list.size() << " TPs.\n"; 
  }
  return os;
};

}
