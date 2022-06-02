/**
 * @file TriggerActivityMakerMichelElectron.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/MichelElectron/TriggerActivityMakerMichelElectron.hpp"
#include "TRACE/trace.h"
#define TRACE_NAME "TriggerActivityMakerMichelElectron"
#include <vector>
#include <algorithm>

using namespace triggeralgs;

void
TriggerActivityMakerMichelElectron::operator()(const TriggerPrimitive& input_tp,
                                               std::vector<TriggerActivity>& output_ta)
{
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

  // Adjacency Threshold Exceeded ============================================================================
  // We've filled the window, now require a sufficient length track AND that the track has a potential Bragg P.
  else if (check_adjacency() > m_adjacency_threshold && m_trigger_on_adjacency && check_bragg_peak() ) { 

     // Flip debug switch to write out useful info - eg. for plotting what we trigger on
     debug=true;
     check_bragg_peak();
     debug=false;

     // Generate a TA with the current window of TPs
     add_window_to_record(m_current_window);
     dump_window_record();
     output_ta.push_back(construct_ta());
     m_current_window.reset(input_tp);
    
  }

  // Otherwise, slide the window along using the current TP.
  else {
    m_current_window.move(input_tp, m_window_length);
  }

  m_primitive_count++;

  return;
}

void
TriggerActivityMakerMichelElectron::configure(const nlohmann::json& config)
{
  // FIX ME: Use some schema here. Also can't work out how to pass booleans.
  if (config.is_object()) {
    if (config.contains("trigger_on_adc"))
      m_trigger_on_adc = config["trigger_on_adc"];
    if (config.contains("trigger_on_n_channels"))
      m_trigger_on_n_channels = config["trigger_on_n_channels"];
    if (config.contains("adc_threshold"))
      m_adc_threshold = config["adc_threshold"];
    if (config.contains("n_channels_threshold"))
      m_n_channels_threshold = config["n_channels_threshold"];
    if (config.contains("window_length"))
      m_window_length = config["window_length"];
    if (config.contains("trigger_on_adjacency"))
      m_trigger_on_adjacency = config["trigger_on_adjacency"];
    if (config.contains("adj_tolerance"))
      m_adj_tolerance = config["adj_tolerance"];
    if (config.contains("adjacency_threshold"))
      m_adjacency_threshold = config["adjacency_threshold"];
  }

}

TriggerActivity
TriggerActivityMakerMichelElectron::construct_ta() const
{

  TriggerPrimitive latest_tp_in_window = m_current_window.inputs.back();

  TriggerActivity ta;
  ta.time_start = m_current_window.time_start;
  ta.time_end = latest_tp_in_window.time_start + latest_tp_in_window.time_over_threshold;
  ta.time_peak = latest_tp_in_window.time_peak;
  ta.time_activity = latest_tp_in_window.time_peak;
  ta.channel_start = latest_tp_in_window.channel;
  ta.channel_end = latest_tp_in_window.channel;
  ta.channel_peak = latest_tp_in_window.channel;
  ta.adc_integral = m_current_window.adc_integral;
  ta.adc_peak = latest_tp_in_window.adc_peak;
  ta.detid = latest_tp_in_window.detid;
  ta.type = TriggerActivity::Type::kTPC;
  ta.algorithm = TriggerActivity::Algorithm::kMichelElectron;
  ta.inputs = m_current_window.inputs;

  return ta;
}

uint16_t
TriggerActivityMakerMichelElectron::check_adjacency() const
{
  // This function returns the adjacency value for the current window, where adjacency
  // is defined as the maximum number of consecutive wires containing hits. It accepts
  // a configurable tolerance paramter, which allows up to adj_tolerance single hit misses
  // on adjacent wires before restarting the adjacency count.

  uint16_t adj = 1;
  uint16_t max = 0; // Maximum adjacency of window, which this function returns
  unsigned int channel = 0;
  unsigned int next_channel = 0;
  unsigned int next = 0;
  unsigned int tol_count = 0;

  // Start and end channels of track - for debugging function
  uint16_t s = 1;
  uint16_t e = 1;

  // Generate a channelID ordered list of hit channels for this window
  std::vector<int> chanList;
  for (auto tp : m_current_window.inputs) {
    chanList.push_back(tp.channel);
  }
  std::sort(chanList.begin(), chanList.end());

  // ADAJACENCY METHOD 1 ===========================================================================================
  // ===============================================================================================================
  // Adjcancency Tolerance = Number of wires we're willing to skip before resetting the adjacency count.
  // This accounts for things like dead channels / missed TPs. Modifiied from HMA, will skip up to 3 consecutive wires.
  for (unsigned int i = 0; i < chanList.size(); ++i) {

    next = (i + 1) % chanList.size(); // End of vec loop
    channel = chanList.at(i);
    next_channel = chanList.at(next);

    // End of vector condition
    if (next_channel == 0) {
      next_channel = channel - 1;
    }

    // Skip same channel hits
    if (next_channel == channel) {
      continue;
    }

    // If next hit is on next channel, increment the adjacency count
    else if (next_channel == channel + 1) {
      ++adj;
    }

    // If next channel is not on the next hit, but the 'second next',
    // increase adjacency but also tally up with the tolerance counter.
    else if ((next_channel == channel + 2) && (tol_count < m_adj_tolerance)) {
      ++adj;
      ++tol_count;
    }
    else if ((next_channel == channel + 3) && (tol_count < m_adj_tolerance)) {
      ++adj;
      ++tol_count;    
      ++tol_count;
    }
    // So we're allowing up to 3 missed hits now, but each missed hit tolls up
    else if ((next_channel == channel + 4) && (tol_count < m_adj_tolerance)) {
      ++adj;
      ++tol_count;
      ++tol_count;
      ++tol_count;
    }

    // If next hit isn't within our reach, end adj count and check for a new max
    else {
      if (adj > max) {
        max = adj;
      }
      adj = 1;
      tol_count = 0;
    }

 }

  // ADJACENCY METHOD 2 ==========================================================================================
  // ===================================================================================================
  // Adjacency Tolerance = Number of consecutive missed wires you're willing to skip
  // before resetting the adjacency count.
  /* for (unsigned int i=0; i < chanList.size(); ++i){

       next = (i+1)%chanList.size();
       channel = chanList.at(i);
       next_channel = chanList.at(next);

       if (next_channel == 0){
          next_channel=channel-1;
       }

       if (next_channel == channel){ continue; }

       else if ((next_channel - channel) < m_adj_tolerance) { ++adj; }

       else {
         if (adj > max){
               max = adj;
       }
       adj = 1;
       tol_count = 0;
       }
    }*/

  return max;
}


// Function contains same functionality as the adjacency checker. The difference is that
// it goes on to use those track hits to try and identify a Bragg peak via a running
// mean average of the ADC values. We use the running mean as it's less susceptible to
// spikes of activity that might trick the algorithm. We establish a baseline, then
// count up clusters of charge deposition above that baseline. If the largest is at
// one of the ends of the track, signal a potential Bragg peak.
bool
TriggerActivityMakerMichelElectron::check_bragg_peak()
{
  // To trigger or not to trigger? The variable which this lengthy function returns
  bool michel = false; 

  int adj = 1;
  int max = 0; 
  unsigned int channel = 0;
  unsigned int next_channel = 0;
  unsigned int next = 0;
  unsigned int tol_count = 0; 

  // Start and end channels of track - for debugging function
  uint16_t s = 1;
  uint16_t e = 1;
  uint16_t fs = 1;
  uint16_t fe = 1;
  long unsigned int st = 0;
  long unsigned int et = 0;
  long unsigned int fst = 0;
  long unsigned int fet = 0;

  // Generate a channelID ordered list of hit channels for the current window
  struct hit {
    int chan;
    long unsigned int startTime;
    uint32_t adc; 
  };
  
  std::vector<hit> chanList;  // Full list of unique channels with hits
  std::vector<hit> trackHits; // List of all hits that contribute to the track/adjacency (incs same channel hits)
  std::vector<hit> finalHits; // Final list of hits that make up track, use at end.
  for (auto tp : m_current_window.inputs) {
     chanList.push_back({tp.channel, tp.time_start, tp.adc_integral});
  }
  // sort chanList by the channel ID, since we want to find the largest consecutive chain of them
  std::sort(chanList.begin(), chanList.end(), [](hit a, hit b) {
		return a.chan < b.chan;	});

  // ADAJACENCY METHOD 1 ===========================================================================================
  // ====================================================================================================
  // Adjcancency Tolerance = Number of times willing to skip a single missed wire before
  // resetting the adjacency count. This accounts for things like dead channels / missed TPs.
  s = chanList.at(0).chan; 
  st = chanList.at(0).startTime;

  for (unsigned int i = 0; i < chanList.size(); ++i) {

    next = (i + 1) % chanList.size(); 
    channel = chanList.at(i).chan;
    next_channel = chanList.at(next).chan;
    
    if (trackHits.size() == 0){
	trackHits.push_back(chanList.at(i));
    }

    // End of vector condition
    if (next_channel == 0) {
      next_channel = channel - 1;
    }

    // Skip same channel hits
    if (next_channel == channel) {
      // But if the same channel hit is nearby, accept it's ADC contribution to the track
      int diff = chanList.at(next).startTime - chanList.at(i).startTime;
      if(std::abs(diff) < 200){
      trackHits.push_back(chanList.at(next)); 
      // Idea here is that two hits generated on the same wire, very close in time are
      // likely coming from the same particle/track activity.
      }
      continue;
    }

    // If next hit is on next channel, increment the adjacency count
    else if (next_channel == channel + 1) {
      ++adj;
      e = next_channel;
      et = chanList.at(next).startTime;
      trackHits.push_back(chanList.at(next));
     }

    // If next channel is not on the next hit, but the 'second next',
    // increase adjacency but also tally up with the tolerance counter.
    else if ((next_channel == channel + 2) && (tol_count < m_adj_tolerance)) {
      ++adj;
      ++tol_count;
      e = next_channel;
      et = chanList.at(next).startTime;
      trackHits.push_back(chanList.at(next));
    }

    else if ((next_channel == channel + 3) && (tol_count < m_adj_tolerance)) {
      ++adj;
      ++tol_count;
      ++tol_count;
      e = next_channel;
      et = chanList.at(next).startTime;
      trackHits.push_back(chanList.at(next));
    }

    else if ((next_channel == channel + 4) && (tol_count < m_adj_tolerance)) {
      ++adj;
      ++tol_count;
      ++tol_count;
      ++tol_count;
      e = next_channel;
      et = chanList.at(next).startTime;
      trackHits.push_back(chanList.at(next));
    }


    // If next hit isn't within our reach, end adj count and check for a new max
    // Also finalise the start and end channels of the adjacency of this window
    else {
      if (adj > max) {
        max = adj;
        fs = s;
	fe = e;
        fst = st;
        fet = et; 
        finalHits = trackHits; // final hits are the ones we will use for checking a Bragg P
       }
      
      // Reset checking variables
      adj = 1;
      tol_count = 0;
      s = next_channel;
      st = chanList.at(next).startTime;
      trackHits.clear(); 
    } 
 }  // End of loop through the window hit channels

  // We now have a vector containing all the hits of a 'track' or above-threshold adjacency. Use these
  // to check for a BP.
  
  std::vector<float> adc_means_list1; // Store our values in this
  std::vector<float> adc_means_list2;
  std::vector<float> adc_means_list3;
  std::vector<float> adc_means_list4;
  std::vector<float> adc_means_list5;
  uint16_t convolve_value1 = 4;       // Number of TPs to take a mean average over
  uint16_t convolve_value2 = 6;
  uint16_t convolve_value3 = 8;
  uint16_t convolve_value4 = 10;
  uint16_t convolve_value5 = 15;
  ;
  // Loop over the track hits
  for (uint16_t i = 0; i < finalHits.size(); ++i){
    float adc_sum = 0;
    float adc_mean = 0;

    // Calculate a few sets of ADC running means, using different params for testing.
    // Obviously we can clean this up when a param has been chosen.
    
    for (uint16_t j = i; j < i+convolve_value1; ++j){
       int hit = (j) % finalHits.size(); 
       adc_sum += finalHits.at(hit).adc;
    }

    adc_mean = adc_sum / convolve_value1;
    adc_means_list1.push_back(adc_mean);
    adc_sum = 0; 

    // CONV PARAM 2
    for (uint16_t j = i; j < i+convolve_value2; ++j){
       int hit = (j) % finalHits.size();  
       adc_sum += finalHits.at(hit).adc;
    }

    adc_mean = adc_sum / convolve_value2;
    adc_means_list2.push_back(adc_mean);
    adc_sum = 0;

    // CONV PARAM 3
    for (uint16_t j = i; j < i+convolve_value3; ++j){
       int hit = (j) % finalHits.size(); 
       adc_sum += finalHits.at(hit).adc;
    }

    adc_mean = adc_sum / convolve_value3;
    adc_means_list3.push_back(adc_mean);
    adc_sum = 0;

    // CONV PARAM 4
    for (uint16_t j = i; j < i+convolve_value4; ++j){
       int hit = (j) % finalHits.size(); 
       adc_sum += finalHits.at(hit).adc;
    } 

    adc_mean = adc_sum / convolve_value4;
    adc_means_list4.push_back(adc_mean);
    adc_sum = 0; 

    // CONV PARAM 5
    for (uint16_t j = i; j < i+convolve_value5; ++j){
       int hit = (j) % finalHits.size();  
       adc_sum += finalHits.at(hit).adc;
    }

    adc_mean = adc_sum / convolve_value5;
    adc_means_list5.push_back(adc_mean);
    adc_sum = 0; 
  
  } 

  // We now have 5 lists of means, for different parameters. We continue with just one here, choosing 8.
  float ped = std::accumulate(adc_means_list3.begin(), adc_means_list3.end(), 0.0) / adc_means_list3.size();
  float tot_adc = std::accumulate(adc_means_list3.begin(), adc_means_list3.end(), 0.0);
  float charge = 0;
  std::vector<float> charge_dumps; // Add clusters of charge here

  // Now go through the list, picking up clusters of charge above the baseline/ped
  for (auto a : adc_means_list3){
    if (a > ped){
       charge += a;
    }
    else if( a < ped && charge !=0 ){
     charge_dumps.push_back(charge);
     charge = 0; 
    } 
  } 

  // If the maximum of that list of charge dumps is near(at?) either end of it, trigger.
  float max_charge = *max_element(charge_dumps.begin(), charge_dumps.end()); 

  // If the highest cluster of charge is at either end of the track, then signal potential BP
  if(max_charge == charge_dumps.front() || max == charge_dumps.back()){
    michel = true;
    }

  // This 'debug' is a switch I use once inside the check in operator() - It shouldn't be used
  // at the condition stage! Tidy this up when Michel trigger is complete.
  if(debug){
    // Output the start and end channel of this window to the debugging file
    std::ofstream outfile;
    outfile.open("adjacnecy_start_end_tps.csv", std::ios_base::app);
    outfile << fs << "," << fe  << "," << fst << "," << fet << std::endl;
    outfile.close();

    // Write out the Chan, Time & ADC values of TPs that contributed to the track
    std::ofstream outfile2;
    outfile2.open("track_tps.csv", std::ios_base::app);
    for(int i = 0 ; i < finalHits.size() ; ++i ){
      outfile2 << finalHits.at(i).chan << "," << finalHits.at(i).startTime << "," <<  finalHits.at(i).adc
      << "," << adc_means_list1.at(i) << "," << adc_means_list2.at(i) << "," << adc_means_list3.at(i) << "," 
      << adc_means_list4.at(i) << "," << adc_means_list5.at(i) << "," << finalHits.size() << std::endl;
    }
    outfile2.close(); 
    }
   
  return michel;
}

// ===============================================================================================
// ===============================================================================================
// Functions below this line are for debugging purposes.
// ===============================================================================================

void
TriggerActivityMakerMichelElectron::add_window_to_record(Window window)
{
  m_window_record.push_back(window);
  return;
}


// Function to dump the details of the TA window currently on record
void
TriggerActivityMakerMichelElectron::dump_window_record()
{
  // FIX ME: Need to index this outfile in the name by detid or something similar.
  std::ofstream outfile;
  outfile.open("window_record_tam.csv", std::ios_base::app);

  for (auto window : m_window_record) {
    outfile << window.time_start << ",";
    outfile << window.inputs.back().time_start << ",";
    outfile << window.inputs.back().time_start - window.time_start << ","; // window_length - from TP start times
    outfile << window.adc_integral << ",";
    outfile << window.n_channels_hit() << ",";       // Number of unique channels with hits
    outfile << window.inputs.size() << ",";          // Number of TPs in Window
    outfile << window.inputs.back().channel << ",";  // Last TP Channel ID
    outfile << window.inputs.front().channel << ","; // First TP Channel ID
    outfile << check_adjacency() << ",";             // New adjacency value for the window
    outfile << check_tot() << std::endl;             // Summed window TOT
  }

  outfile.close();

  m_window_record.clear();

  return;
}

// Function to add current TP details to a text file for testing and debugging.
void
TriggerActivityMakerMichelElectron::dump_tp(TriggerPrimitive const& input_tp)
{
  std::ofstream outfile;
  outfile.open("coldbox_tps.txt", std::ios_base::app);

  // Output relevant TP information to file
  outfile << input_tp.time_start << " ";          // Start time of TP
  outfile << input_tp.time_over_threshold << " "; // in multiples of 25
  outfile << input_tp.time_peak << " ";           //
  outfile << input_tp.channel << " ";             // Offline channel ID
  outfile << input_tp.adc_integral << " ";        // ADC Sum
  outfile << input_tp.adc_peak << " ";            // ADC Peak Value
  outfile << input_tp.detid << " ";               // Det ID - Identifies detector element, APA or PDS part etc...
  outfile << input_tp.type << std::endl;          // This should now write out TPs in the same 'coldBox' way.
  outfile.close();

  return;
}

int
TriggerActivityMakerMichelElectron::check_tot() const
{
  // Here, we just want to sum up all the tot values for each TP within window, and return this tot of the window.
  int window_tot = 0; // The window TOT, which this function returns

  for (auto tp : m_current_window.inputs) {
    window_tot += tp.time_over_threshold;
  }

  return window_tot;
}

/*
void
TriggerActivityMakerMichelElectron::flush(timestamp_t, std::vector<TriggerActivity>& output_ta)
{
  // Check the status of the current window, construct TA if conditions are met. Regardless
  // of whether the conditions are met, reset the window.
  if(m_current_window.adc_integral > m_adc_threshold && m_trigger_on_adc){
  //else if(m_current_window.adc_integral > m_conf.adc_threshold && m_conf.trigger_on_adc){
    //TLOG_DEBUG(TRACE_NAME) << "ADC integral in window is greater than specified threshold.";
    output_ta.push_back(construct_ta());
  }
  else if(m_current_window.n_channels_hit() > m_n_channels_threshold && m_trigger_on_n_channels){
  //else if(m_current_window.n_channels_hit() > m_conf.n_channels_threshold && m_conf.trigger_on_n_channels){
    //TLOG_DEBUG(TRACE_NAME) << "Number of channels hit in the window is greater than specified threshold.";
    output_ta.push_back(construct_ta());
  }

  //TLOG_DEBUG(TRACE_NAME) << "Clearing the current window, on the arrival of the next input_tp, the window will be
reset."; m_current_window.clear();

  return;
}*/
