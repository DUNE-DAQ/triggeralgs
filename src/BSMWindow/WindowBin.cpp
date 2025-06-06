#include "triggeralgs/BSMWindow/WindowBin.hpp"

namespace triggeralgs {

bool WindowBin::is_empty() const {
  return tp_list.empty();
}

void WindowBin::add(TriggerPrimitive const &input_tp) {
  // Add the input TP's contribution to the total ADC and add it to
  // the TP list.
  adc_integral += input_tp.adc_integral;
  tp_list.push_back(input_tp);
}

void WindowBin::clear() {
  tp_list.clear();
}

void WindowBin::move(TriggerPrimitive const &input_tp, timestamp_t const &window_length) {
  // Find all of the TPs in the window that need to be removed
  // if the input_tp is to be added and the size of the bin
  // is to be conserved.
  // Substract those TPs' contribution from the total bin ADC.
  uint32_t n_tps_to_erase = 0;
  for(auto tp : tp_list){
    if(!(input_tp.time_start-tp.time_start < window_length)){
      n_tps_to_erase++;
      adc_integral -= tp.adc_integral;
    }
    else break;
  }
  // Erase the TPs from the bin.
  tp_list.erase(tp_list.begin(), tp_list.begin()+n_tps_to_erase);
  // Make the bin start time the start time of what is now the
  // first TP.
  if (tp_list.size() != 0) {
    time_start = tp_list.front().time_start;
    add(input_tp);
  }
  else reset(input_tp);
}

void WindowBin::reset(TriggerPrimitive const &input_tp){
  // Empty the TP list.
  tp_list.clear();
  // Set the start time of the window to be the start time of the 
  // input_tp.
  time_start = input_tp.time_start;
  // Start the total ADC integral.
  adc_integral = input_tp.adc_integral;
  // Add the input TP to the TP list.
  tp_list.push_back(input_tp);
}

void WindowBin::reset(TriggerPrimitive const &input_tp, timestamp_t const &bin_time_start){
  // Empty the TP list.
  tp_list.clear();
  // Set the start time of the window to be the start time of the 
  // the next bin.
  time_start = bin_time_start;
  // Start the total ADC integral.
  adc_integral = input_tp.adc_integral;
  // Add the input TP to the TP list.
  tp_list.push_back(input_tp);
}

void WindowBin::initbinempty(timestamp_t const &bin_time_start){
  // Empty the TP list.
  tp_list.clear();
  // Set the start time of the window to be the start time of the 
  // input_tp.
  time_start = bin_time_start;
  // Start the total ADC integral.
  adc_integral = 0;
}

std::ostream& operator<<(std::ostream& os, const WindowBin& window){
  if(window.is_empty()) os << "Bin is empty!\n";
  else{
    os << "Bin start: " << window.time_start << ", end: " << window.tp_list.back().time_start << "\n";
    //os << "Time difference between start and end of bin: " << window.time_start - window.tp_list.back().time_start << "\n";
    os << ". Total of: " << window.adc_integral << " ADC counts with " << window.tp_list.size() << " TPs.\n"; 
  }
  return os;
}

} // namesapce triggeralgs
