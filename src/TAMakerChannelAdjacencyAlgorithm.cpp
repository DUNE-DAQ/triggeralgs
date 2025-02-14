/**
 * @file TAMakerChannelAdjacencyAlgorithm.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/ChannelAdjacency/TAMakerChannelAdjacencyAlgorithm.hpp"
#include "TRACE/trace.h"
#include "triggeralgs/Logging.hpp"
#define TRACE_NAME "TAMakerChannelAdjacencyAlgorithm"
#include <math.h>
#include <vector>

using namespace triggeralgs;

using Logging::TLVL_DEBUG_LOW;

void
TAMakerChannelAdjacencyAlgorithm::process(const TriggerPrimitive& input_tp,
                                              std::vector<TriggerActivity>& output_ta)
{

  // Add useful info about recived TPs here for FW and SW TPG guys.
  if (m_print_tp_info) {
    TLOG_DEBUG(TLVL_DEBUG_LOW) << " ########## m_current_window is reset ##########\n"
                               << " TP Start Time: " << input_tp.time_start << ", TP ADC Sum: " << input_tp.adc_integral
                               << ", TP TOT: " << input_tp.time_over_threshold << ", TP ADC Peak: " << input_tp.adc_peak
                               << ", TP Offline Channel ID: " << input_tp.channel << "\n";
  }

  // 0) FIRST TP =====================================================================
  // The first time process() is called, reset the window object.
  if (m_current_window.is_empty()) {
    m_current_window.reset(input_tp);
    return;
  }

  // If the difference between the current TP's start time and the start of the window
  // is less than the specified window size, add the TP to the window.
  bool adj_pass = 0;      // sets to true when adjacency logic is satisfied
  bool window_filled = 1; // sets to true when window is ready to test the adjacency logic
  if ((input_tp.time_start - m_current_window.time_start) < m_window_length) {
    m_current_window.add(input_tp);
    window_filled = 0;
    TLOG_DEBUG(TLVL_DEBUG_LOW) << "m_current_window.time_start " << m_current_window.time_start << "\n";
  }

  else {
    TPWindow win_adj_max;

    bool ta_found = 1;
    while (ta_found) {

      // make m_current_window_tmp a copy of m_current_window and clear m_current_window
      TPWindow m_current_window_tmp = m_current_window;
      m_current_window.clear();

      // make m_current_window a new window of non-overlapping tps (of m_current_window_tmp and win_adj_max)
      for (auto tp : m_current_window_tmp.inputs) {
        bool new_tp = 1;
        for (auto tp_sel : win_adj_max.inputs) {
          if (tp.channel == tp_sel.channel) {
            new_tp = 0;
            break;
          }
        }
        if (new_tp)
          m_current_window.add(tp);
      }

      // check adjacency -> win_adj_max now contains only those tps that make the track
      win_adj_max = check_adjacency();
      if (win_adj_max.inputs.size() > 0) {

        adj_pass = 1;
        ta_found = 1;
        output_ta.push_back(construct_ta(win_adj_max));
      } else
        ta_found = 0;
    }
    if (adj_pass)
      m_current_window.reset(input_tp);
  }

  // if adjacency logic is not true, slide the window along using the current TP.
  if (window_filled && !adj_pass) {
    m_current_window.move(input_tp, m_window_length);
  }

  return;
}

void
TAMakerChannelAdjacencyAlgorithm::configure(const nlohmann::json& config)
{
  TriggerActivityMaker::configure(config);
  if (config.is_object()) {
    if (config.contains("window_length"))
      m_window_length = config["window_length"];
    if (config.contains("adjacency_tolerance"))
      m_adj_tolerance = config["adjacency_tolerance"];
    if (config.contains("adjacency_threshold"))
      m_adjacency_threshold = config["adjacency_threshold"];
    if (config.contains("print_tp_info"))
      m_print_tp_info = config["print_tp_info"];
  }
}

TriggerActivity
TAMakerChannelAdjacencyAlgorithm::construct_ta(TPWindow win_adj_max) const
{

  TriggerActivity ta;

  TriggerPrimitive last_tp = win_adj_max.inputs.back();

  ta.time_start = last_tp.time_start;
  ta.time_end = last_tp.time_start;
  ta.time_peak = last_tp.time_peak;
  ta.time_activity = last_tp.time_peak;
  ta.channel_start = last_tp.channel;
  ta.channel_end = last_tp.channel;
  ta.channel_peak = last_tp.channel;
  ta.adc_integral = win_adj_max.adc_integral;
  ta.adc_peak = last_tp.adc_peak;
  ta.detid = last_tp.detid;
  ta.type = TriggerActivity::Type::kTPC;
  ta.algorithm = TriggerActivity::Algorithm::kChannelAdjacency;
  ta.inputs = win_adj_max.inputs;

  for (const auto& tp : ta.inputs) {
    ta.time_start = std::min(ta.time_start, tp.time_start);
    ta.time_end = std::max(ta.time_end, tp.time_start);
    ta.channel_start = std::min(ta.channel_start, tp.channel);
    ta.channel_end = std::max(ta.channel_end, tp.channel);
    if (tp.adc_peak > ta.adc_peak) {
      ta.time_peak = tp.time_peak;
      ta.adc_peak = tp.adc_peak;
      ta.channel_peak = tp.channel;
    }
  }

  return ta;
}

// std::vector<TriggerPrimitive>
TPWindow
TAMakerChannelAdjacencyAlgorithm::check_adjacency()
{
  // This function deals with tp window (m_current_window), select adjacent tps (with a channel gap from 0 to 5; sum of
  // all gaps < m_adj_tolerance), checks if track length > m_adjacency_threshold: return the tp window (win_adj_max,
  // which is subset of the input tp window)

  unsigned int channel = 0;      // Current channel ID
  unsigned int next_channel = 0; // Next channel ID
  unsigned int next = 0;         // The next position in the hit channels vector
  unsigned int tol_count = 0;    // Tolerance count, should not pass adj_tolerance

  // Generate a channelID ordered list of hit channels for this window; second element of pair is tps
  std::vector<std::pair<int, TriggerPrimitive>> chanTPList;
  for (auto tp : m_current_window.inputs) {
    chanTPList.push_back(std::make_pair(tp.channel, tp));
  }
  std::sort(chanTPList.begin(),
            chanTPList.end(),
            [](const std::pair<int, TriggerPrimitive>& a, const std::pair<int, TriggerPrimitive>& b) {
              return (a.first < b.first);
            });

  // ADAJACENCY LOGIC ====================================================================
  // =====================================================================================
  // Adjcancency Tolerance = Number of times prepared to skip missed hits before resetting
  // the adjacency count (win_adj). This accounts for things like dead channels / missed TPs.

  // add first tp, and then if tps are on next channels (check code below to understand the definition)
  TPWindow win_adj;
  TPWindow win_adj_max; // if track length > m_adjacency_threshold, set win_adj_max = win_adj; return win_adj_max;

  for (int i = 0; i < chanTPList.size(); ++i) {

    win_adj_max.clear();

    next = (i + 1) % chanTPList.size(); // Loops back when outside of channel list range
    channel = chanTPList.at(i).first;
    next_channel = chanTPList.at(next).first; // Next channel with a hit

    // End of vector condition.
    if (next == 0) {
      next_channel = channel - 1;
    }

    // Skip same channel hits.
    if (next_channel == channel)
      continue;

    // If win_adj size == zero, add current tp
    if (win_adj.inputs.size() == 0)
      win_adj.add(chanTPList[i].second);

    // If next hit is on next channel, increment the adjacency count
    if (next_channel - channel == 1) {
      win_adj.add(chanTPList[next].second);
    }

    // Allow a max gap of 5 channels (e.g., 45 and 50; 46, 47, 48, 49 are missing); increment the adjacency count
    // Sum of gaps should be < adj_tolerance (e.g., if toleance is 30, the max total gap can vary from 0 to 29+4 = 33)
    else if (next_channel - channel > 0 && next_channel - channel <= 5 && tol_count < m_adj_tolerance) {
      win_adj.add(chanTPList[next].second);
      tol_count += next_channel - channel - 1;
    }

    // if track length > m_adjacency_threshold, set win_adj_max = win_adj;
    else if (win_adj.inputs.size() > m_adjacency_threshold) {
      win_adj_max = win_adj;
      break;
    }

    // If track length < m_adjacency_threshold, reset variables for next iteration.
    else {
      tol_count = 0;
      win_adj.clear();
    }
  }

  return win_adj_max;
}

// =====================================================================================
// Functions below this line are for debugging purposes.
// =====================================================================================
void
TAMakerChannelAdjacencyAlgorithm::add_window_to_record(TPWindow window)
{
  m_window_record.push_back(window);
  return;
}

// Register algo in TA Factory
REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TAMakerChannelAdjacencyAlgorithm)
