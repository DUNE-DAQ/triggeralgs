/**
 * @file TriggerActivityMakerChannelTimeAdjacency.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/ChannelTimeAdjacency/TriggerActivityMakerChannelTimeAdjacency.hpp"
#include "triggeralgs/Logging.hpp"
#include "TRACE/trace.h"
#define TRACE_NAME "TriggerActivityMakerChannelTimeAdjacencyPlugin"
#include <vector>
#include <math.h>

using namespace triggeralgs;

using Logging::TLVL_DEBUG_LOW;

void
TriggerActivityMakerChannelTimeAdjacency::operator()(const TriggerPrimitive& input_tp,
					     std::vector<TriggerActivity>& output_ta)
{

  uint16_t adjacency;

  // Add useful info about recived TPs here for FW and SW TPG guys.
  if (m_print_tp_info){
    TLOG(1) << "TP Start Time: " << input_tp.time_start << ", TP ADC Sum: " <<  input_tp.adc_integral
	    << ", TP TOT: " << input_tp.time_over_threshold << ", TP ADC Peak: " << input_tp.adc_peak
     	<< ", TP Offline Channel ID: " << input_tp.channel;
    
    TLOG(1) << "Adjacency of current window is: " << check_adjacency();    
  }


  // 0) FIRST TP =====================================================================
  // The first time operator() is called, reset the window object.
  if (m_current_window.is_empty()) {
    m_current_window.reset(input_tp);
    m_primitive_count++;
    return;
  }

  // If the difference between the current TP's start time and the start of the window
  // is less than the specified window size, add the TP to the window.
  if ((input_tp.time_start - m_current_window.time_start) < m_window_length) {
    m_current_window.add(input_tp);
  }

  // 1) ADJACENCY THRESHOLD EXCEEDED ==================================================
  // If the addition of the current TP to the window would make it longer than the
  // specified window length, don't add it but check whether the adjacency of the
  // current window exceeds the configured threshold. If it does, and we are triggering
  // on adjacency, then create a TA and reset the window with the new/current TP.
  else if ((adjacency = check_adjacency()) > m_adjacency_threshold) {
    m_ta_count++;
    if (m_ta_count % m_prescale == 0){   

    	// Check for a new maximum, display the largest seen adjacency in the log.
    	if (adjacency > m_max_adjacency) { m_max_adjacency = adjacency; }
    	TLOG_DEBUG(TRACE_NAME) << "Emitting track and multiplicity TA with adjacency " << check_adjacency() <<
                   " and multiplicity " << m_longest_track_window.n_channels_hit() << ". The ADC integral of this TA is " << 
                   m_longest_track_window.adc_integral << " and the largest longest track seen so far is " << m_max_adjacency;

      output_ta.push_back(construct_ta()); // Construct TA and add to output TA vector
    	m_current_window.reset(input_tp); // Reset the window with the current TP
     }
  }

  // 2) Otherwise, slide the window along using the current TP.
  else {
    m_current_window.move(input_tp, m_window_length); // Move the window along
  }

  using namespace std::chrono;
  // If this is the first TP of the run, calculate the initial offset:
  if (m_primitive_count == 0){
   m_initial_offset = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - input_tp.time_start*16*1e-6;
  }
  
  // Update OpMon Variable(s)
  uint64_t system_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  uint64_t data_time = input_tp.time_start*16*1e-6;                              // Convert 62.5 MHz ticks to ms
  m_data_vs_system_time.store(fabs(system_time - data_time - m_initial_offset)); // Store the difference for OpMon*/
  m_primitive_count++;

  return;
}

void
TriggerActivityMakerChannelTimeAdjacency::configure(const nlohmann::json& config)
{
  if (config.is_object()) {
    if (config.contains("time_tolerance"))
      m_time_tolerance = config["time_tolerance"];
    if (config.contains("window_length"))
      m_window_length = config["window_length"];
    if (config.contains("adj_tolerance"))
      m_adj_tolerance = config["adj_tolerance"];
    if (config.contains("adjacency_threshold"))
      m_adjacency_threshold = config["adjacency_threshold"];
    if (config.contains("print_tp_info"))
      m_print_tp_info = config["print_tp_info"];
    if (config.contains("prescale"))
      m_prescale = config["prescale"]; 
 }

}

TriggerActivity
TriggerActivityMakerChannelTimeAdjacency::construct_ta() const
{

  TriggerActivity ta;
  
  TriggerPrimitive last_tp = m_longest_track_window.inputs.back();

  ta.time_start = last_tp.time_start;
  ta.time_end = last_tp.time_start+last_tp.time_over_threshold;
  ta.time_peak = last_tp.time_peak;
  ta.time_activity = last_tp.time_peak;
  ta.channel_start = last_tp.channel;
  ta.channel_end = last_tp.channel;
  ta.channel_peak = last_tp.channel;
  ta.adc_integral = m_longest_track_window.adc_integral;
  ta.adc_peak = last_tp.adc_integral;
  ta.detid = last_tp.detid;
  ta.type = TriggerActivity::Type::kTPC;
  ta.algorithm = TriggerActivity::Algorithm::kChannelTimeAdjacency;
  ta.inputs = m_longest_track_window.inputs;


  for( const auto& tp : ta.inputs ) {
    ta.time_start = std::min(ta.time_start, tp.time_start);
    ta.time_end = std::max(ta.time_end, tp.time_start+tp.time_over_threshold);
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

uint16_t
TriggerActivityMakerChannelTimeAdjacency::check_adjacency() 
{
  uint16_t adj = 1;              // Initialize adjacency, 1 for the first wire
  uint16_t max = 0;              // Maximum adjacency of window, which this function returns
  unsigned int channel_diff;     // Channel difference between to consecutive TPs of a ChannelID ordered TP vector
  unsigned int index;            // Index of the previous TP satisfying the adjacency condition
  int64_t start_time_diff;       // Start time difference between to consecutive TPs of a ChannelID ordered TP vector
  unsigned int tol_count = 0;    // Tolerance count, should not pass adj_tolerance
  m_longest_track_window.clear(); // Clear the longest track window

  std::vector<TriggerPrimitive> tp_inputs = m_current_window.inputs;
  std::vector<TriggerPrimitive> tp_track;
  std::vector<TriggerPrimitive> tp_longest_track;

  // Generate a channelID ordered list of hit channels for this window: m_current_window
  std::sort(tp_inputs.begin(), tp_inputs.end(), [](const TriggerPrimitive& tp1, const TriggerPrimitive& tp2) {
    return tp1.channel < tp2.channel;
  });

  // Loop over the TPs of the current window
  for (unsigned int i=0; i < tp_inputs.size(); i++){
    // Initiate/Resume the search with the first/a TP of the current window
    tp_track.push_back(tp_inputs.at(i));
    // index corresponds to the position of the latest TP of the current track
    index = i;
    unsigned int j=i+1; // j index to compare TPs further than the TP at position index
    channel_diff = 0; // To access the while loop for every iteration of i
    // Loop over the TPs of the current window to find the longest track
    while (j < tp_inputs.size() && (channel_diff == 1 || channel_diff == 0)){
      channel_diff = tp_inputs.at(j).channel - tp_inputs.at(index).channel;
      start_time_diff = std::abs(static_cast<int64_t>(tp_inputs.at(j).time_start) - static_cast<int64_t>(tp_inputs.at(index).time_start));
      // Check adjacency from that TP at position i. Add next TP and adjacency if the condition is fulfilled
      if (channel_diff == 1 && start_time_diff < m_time_tolerance){
        tp_track.push_back(tp_inputs.at(j));
        adj++;
        index = j;
      }
      // Check adjacency from TP at position i. Add only next TP if the condition is fulfilled
      else if (channel_diff == 0 && start_time_diff < m_time_tolerance){
        tp_track.push_back(tp_inputs.at(j));
        index = j;
      }

      // If next channel is not on the next hit, but the 'second next', increase adjacency 
      // but also tally up with the tolerance counter.
      else if ((channel_diff <= 5 && start_time_diff < channel_diff*m_time_tolerance) && (tol_count < m_adj_tolerance)) {
        tp_track.push_back(tp_inputs.at(j));
        adj++;
        index = j;
        tol_count += channel_diff - 1;
        channel_diff = 0; // To stay in the while loop
      }

      j++;
    } // End of while loop

    // Verify if new adjacency exceeds the max value. If so, max and tp_longest_track are updated. 
    if(adj > max){ 
      max = adj;
      tp_longest_track = tp_track;
    }
    // Update the counter and reset tp_track (TP vector)
    adj = 1;
    tp_track.clear();
  } // End of for loop

  // Add the TPs that caused the adjacency to be the global maximum after channel-time filtering
  for (auto tp : tp_longest_track) {
    m_longest_track_window.add(tp);
  }

  return max;
}

//////////////////////////////////////////////////
// For debugging and performance study purposes // 
//////////////////////////////////////////////////

void
TriggerActivityMakerChannelTimeAdjacency::add_window_to_record(TPWindow window)
{
  m_window_record.push_back(window);
  return;
}

void
TriggerActivityMakerChannelTimeAdjacency::dump_window_record()
{
  // To output the window sizes and quotient into a file for debugging purposes
  uint16_t longestTrackSize, currentWindowSize;
  double quotient;
  
  // Output the window sizes to a file
  std::ofstream outputFile("window_sizes_time_filtered.txt", std::ios::app);
  if (outputFile.is_open()) {
    // Check if it's the first row (first fragment) and write the variable names
    if (m_fragment_count==0) {
      outputFile << "LongestTrackSize,CurrentWindowSize,Quotient(%)" << std::endl;
    }

    // Write the window sizes and quotient
    longestTrackSize = m_longest_track_window.inputs.size();
    currentWindowSize = m_current_window.inputs.size();
    quotient = static_cast<double>(longestTrackSize) / currentWindowSize * 100;

    outputFile << longestTrackSize << "," << currentWindowSize << "," << quotient << std::endl;

    outputFile.close();
  } else {
    std::cerr << "Unable to open the output file." << std::endl;
  }
}

void
TriggerActivityMakerChannelTimeAdjacency::dump_longest_track_record_channel_ordered()
{
  // Output the TP info of the longest track to a file
  std::ofstream tpInfoFile("tp_info_longest_track_time_filtered.txt", std::ios::app);
  if (tpInfoFile.is_open()) {
    if (m_fragment_count == 0) {
      tpInfoFile << "Longest Track TP Information" << std::endl;
      tpInfoFile << "TP index, Channel, Relative Start Time (ticks), Relative Time Difference (ticks)" << std::endl;
    }
    
    tpInfoFile << "Fragment number: " << m_fragment_count << std::endl;

    // Calculate the minimum start time
    timestamp_t minStartTime = std::numeric_limits<timestamp_t>::max();
    if (!m_longest_track_window.inputs.empty()) {
      minStartTime = std::min_element(m_longest_track_window.inputs.begin(), m_longest_track_window.inputs.end(),
        [](const auto& tp1, const auto& tp2) {
          return tp1.time_start < tp2.time_start;
        })->time_start;
    }

    int tp_index = 0;
    TriggerPrimitive tp_former;
    for (const auto& tp : m_longest_track_window.inputs) {
      if(tp_index==0) tp_former = tp;
      tpInfoFile << tp_index << "," << tp.channel << "," << (tp.time_start - minStartTime)  << "," << std::abs(static_cast<int64_t>(tp.time_start) - static_cast<int64_t>(tp_former.time_start)) << std::endl; // static_cast<double> used to prevent uncompatible negative timestamp
      tp_former = tp;
      tp_index++;
    }

    tpInfoFile.close();
  } else {
    std::cerr << "Unable to open the longest track TP info file." << std::endl;
  }
}

void
TriggerActivityMakerChannelTimeAdjacency::dump_longest_track_record_time_ordered()
{
  // Output the TP info of the longest track to a file ordered by time, not by channel
  std::ofstream tpInfoFileTimeOrdered("tp_info_longest_track_time_ordered_time_filtered.txt", std::ios::app);
  if (tpInfoFileTimeOrdered.is_open()) {
    if (m_fragment_count == 0) {
      tpInfoFileTimeOrdered << "Longest Track TP Information" << std::endl;
      tpInfoFileTimeOrdered << "TP index, Channel, Relative Start Time (ticks), Relative Time Difference (ticks)" << std::endl;
    }
    
    tpInfoFileTimeOrdered << "Fragment number: " << m_fragment_count << std::endl;

    // Calculate the minimum start time
    timestamp_t minStartTime = std::numeric_limits<timestamp_t>::max();
    if (!m_longest_track_window.inputs.empty()) {
      minStartTime = std::min_element(m_longest_track_window.inputs.begin(), m_longest_track_window.inputs.end(),
        [](const auto& tp1, const auto& tp2) {
          return tp1.time_start < tp2.time_start;
        })->time_start;
    }

    // Generate a Time ordered list of hit channels for this window: m_longest_track_window
    std::sort(m_longest_track_window.inputs.begin(), m_longest_track_window.inputs.end(), [](const TriggerPrimitive& tp1, const TriggerPrimitive& tp2) {
      return tp1.time_start < tp2.time_start;
    });

    int tp_index = 0;
    TriggerPrimitive tp_former;
    for (const auto& tp : m_longest_track_window.inputs) {
      if(tp_index==0) tp_former = tp;
      tpInfoFileTimeOrdered << tp_index << "," << tp.channel << "," << (tp.time_start - minStartTime)  << "," << std::abs(static_cast<int64_t>(tp.time_start) - static_cast<int64_t>(tp_former.time_start)) << std::endl; // static_cast<double> used to prevent uncompatible negative timestamp
      tp_former = tp;
      tp_index++;
    }

    tpInfoFileTimeOrdered.close();
  } else {
    std::cerr << "Unable to open the longest track TP info file." << std::endl;
  }
}

// Register algo in TA Factory
REGISTER_TRIGGER_ACTIVITY_MAKER(TRACE_NAME, TriggerActivityMakerChannelTimeAdjacency)
