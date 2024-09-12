/**
 * @file TriggerActivityMakerChannelTimeAdjacency.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_CHANNELTIMEADJACENCY_TRIGGERACTIVITYMAKERCHANNELTIMEADJACENCY_HPP_
#define TRIGGERALGS_CHANNELTIMEADJACENCY_TRIGGERACTIVITYMAKERCHANNELTIMEADJACENCY_HPP_

#include "triggeralgs/TPWindow.hpp"
#include "triggeralgs/TriggerActivityFactory.hpp"
#include <fstream>
#include <vector>

namespace triggeralgs {
class TriggerActivityMakerChannelTimeAdjacency : public TriggerActivityMaker
{
public:
  void operator()(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta);
  void configure(const nlohmann::json& config);

private:
  TriggerActivity construct_ta() const;

  uint16_t check_adjacency();         // Returns longest string of adjacent collection hits in window

  TPWindow m_current_window;          // Holds collection hits only
  TPWindow m_longest_track_window;    // Holds collection hits only for the longest track of the current window provided the adjacency threshold is exceeded
  uint64_t m_primitive_count = 0;     
  uint16_t m_fragment_count = 0;      // Fragment counter

  // Configurable parameters.
  bool m_print_tp_info = false;          // Prints out some information on every TP received
  uint16_t m_adjacency_threshold = 15;   // Default is 15 wire track for testing
  int m_max_adjacency = 0;               // The maximum adjacency seen so far in any window
  uint16_t m_adj_tolerance = 3;          // Adjacency tolerance - default is 3 from coldbox testing.
  uint16_t m_time_tolerance = 150;       // Time tolerance, in ticks, to filter out TPs not correlated in time in the saved TA for the longest track.
  timestamp_t m_window_length = 8000;    // Shouldn't exceed the max drift which is ~9375 62.5 MHz ticks for VDCB
  uint16_t m_ta_count = 0;               // Use for prescaling
  uint16_t m_prescale = 1;               // Prescale value, defult is one, trigger every TA

  // For debugging and performance study purposes
  void add_window_to_record(TPWindow window);
  void dump_window_record();
  void dump_longest_track_record_channel_ordered();
  void dump_longest_track_record_time_ordered();
  std::vector<TPWindow> m_window_record;
};
} // namespace triggeralgs
#endif // TRIGGERALGS_CHANNELTIMEADJACENCY_TRIGGERACTIVITYMAKERCHANNELTIMEADJACENCY_HPP_
