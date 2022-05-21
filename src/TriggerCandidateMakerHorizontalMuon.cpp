/**
 * @file TriggerCandidateMakerHorizontalMuon.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/HorizontalMuon/TriggerCandidateMakerHorizontalMuon.hpp"

#include "TRACE/trace.h"
#define TRACE_NAME "TriggerCandidateMakerHorizontalMuon"

#include <vector>

using namespace triggeralgs;

void
TriggerCandidateMakerHorizontalMuon::operator()(const TriggerActivity& activity,
                                                std::vector<TriggerCandidate>& output_tc)
{

  std::vector<TriggerActivity::TriggerActivityData> ta_list = { static_cast<TriggerActivity::TriggerActivityData>(
    activity) };

  // The first time operator is called, reset window object.
  if (m_current_window.is_empty()) {
    m_current_window.reset(activity);
    m_activity_count++;

    // Trivial TC Logic:
    // Simply construct a TC for all TAs passed to this TCMaker

    // add_window_to_record(m_current_window);
    // dump_window_record();

    TriggerCandidate tc = construct_tc();
    output_tc.push_back(tc);

    // Clear the current window (only has a single TA in it)
    m_current_window.clear();
 
    return;
  }

  // ===================================== TA Clustering ====================================================== 
  // Currently the clustering code below this line isn't used, since we use a trivial logic above, triggering
  // on any single TA passed to the TCMaker and then clearing the window of that single TA. However it will be
  // used in the future so should remain.  

  // FIX ME: Only want to call this if running in debug mode.
  // add_window_to_record(m_current_window);

  // If the difference between the current TA's start time and the start of the window
  // is less than the specified window size, add the TA to the window.
  if ((activity.time_start - m_current_window.time_start) < m_window_length) {
    // TLOG_DEBUG(TRACE_NAME) << "Window not yet complete, adding the activity to the window.";
    m_current_window.add(activity);
  }

  // If the addition of the current TA to the window would make it longer
  // than the specified window length, don't add it but check whether the sum of all adc in
  // the existing window is above the specified threshold. If it is, and we are triggering on ADC,
  // make a TA and start a fresh window with the current TP.
  else if (m_current_window.adc_integral > m_adc_threshold && m_trigger_on_adc) {
    // TLOG_DEBUG(TRACE_NAME) << "ADC integral in window is greater than specified threshold.";
    TriggerCandidate tc = construct_tc();
    output_tc.push_back(tc);
    // TLOG_DEBUG(TRACE_NAME) << "Resetting window with activity.";
    m_current_window.reset(activity);
  }

  // If the addition of the current TA to the window would make it longer
  // than the specified window length, don't add it but check whether the number of hit channels in
  // the existing window is above the specified threshold. If it is, and we are triggering on channels,
  // make a TC and start a fresh window with the current TA.
  else if (m_current_window.n_channels_hit() > m_n_channels_threshold && m_trigger_on_n_channels) {
    tc_number++;
    output_tc.push_back(construct_tc());
    m_current_window.reset(activity);
  }
 
  // If it is not, move the window along.
  else {
    // TLOG_DEBUG(TRACE_NAME) << "Window is at required length but specified threshold not met, shifting window along.";
    m_current_window.move(activity, m_window_length);
  }

  m_activity_count++;

  //  if(m_activity_count % 500 == 0) dump_window_record();

  return;
}

void
TriggerCandidateMakerHorizontalMuon::configure(const nlohmann::json& config)
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
    if (config.contains("readout_window_ticks_before"))
      m_readout_window_ticks_before = config["readout_window_ticks_before"];
    if (config.contains("readout_window_ticks_after"))
      m_readout_window_ticks_after = config["readout_window_ticks_after"];

    // if (config.contains("channel_map")) m_channel_map = config["channel_map"];
  }
  /*if(m_trigger_on_adc) {
    TLOG_DEBUG(TRACE_NAME) << "If the total ADC of trigger activities with times within a "
                           << m_window_length << " tick time window is above " << m_adc_threshold << " counts, a trigger
  will be issued.";
  }
  else if(m_trigger_on_n_channels) {
    TLOG_DEBUG(TRACE_NAME) << "If the total number of channels with hits within a "
                           << m_window_length << " tick time window is above " << m_n_channels_threshold << " channels,
  a trigger will be issued.";
  }
  else if ((!m_trigger_on_adc) && (!m_trigger_on_n_channels)) {
    TLOG_DEBUG(TRACE_NAME) << "The candidate maker will construct candidates 1 for 1 from trigger activities.";
  }
  else if (m_trigger_on_adc && m_trigger_on_n_channels) {
    TLOG() << "You have requsted to trigger on both the number of channels hit and the sum of adc counts, "
           << "unfortunately this is not yet supported. Exiting.";
    // FIX ME: Logic to throw an exception here.
  }*/

  return;
}

TriggerCandidate
TriggerCandidateMakerHorizontalMuon::construct_tc() const
{
  TriggerActivity latest_ta_in_window = m_current_window.inputs.back();

  TriggerCandidate tc;
  tc.time_start = m_current_window.time_start - m_readout_window_ticks_before;
  tc.time_end =
    latest_ta_in_window.inputs.back().time_start + latest_ta_in_window.inputs.back().time_over_threshold + m_readout_window_ticks_after;
  tc.time_candidate = m_current_window.time_start;
  tc.detid = latest_ta_in_window.detid;
  tc.type = TriggerCandidate::Type::kHorizontalMuon;
  tc.algorithm = TriggerCandidate::Algorithm::kHorizontalMuon;

  // Take the list of triggeralgs::TriggerActivity in the current
  // window and convert them (implicitly) to detdataformats'
  // TriggerActivityData, which is the base class of TriggerActivity
  for (auto& ta : m_current_window.inputs) {
    tc.inputs.push_back(ta);
  }

  return tc;
}

bool
TriggerCandidateMakerHorizontalMuon::check_adjacency() const
{
  // FIX ME: An adjacency check on the channels which have hits.
  return true;
}

// Functions below this line are for debugging purposes.
void
TriggerCandidateMakerHorizontalMuon::add_window_to_record(Window window)
{
  m_window_record.push_back(window);
  return;
}

void
TriggerCandidateMakerHorizontalMuon::dump_window_record()
{
  // FIX ME: Need to index this outfile in the name by detid or something similar.
  std::ofstream outfile;
  outfile.open("window_record_tcm.csv", std::ios_base::app);

  for (auto window : m_window_record) {
    outfile << window.time_start << ",";
    outfile << window.inputs.back().time_start << ",";
    outfile << window.inputs.back().time_start - window.time_start << ",";
    outfile << window.adc_integral << ",";
    outfile << window.n_channels_hit() << ",";
    outfile << window.inputs.size() << std::endl;
  }

  outfile.close();

  m_window_record.clear();

  return;
}

/*
void
TriggerCandidateMakerHorizontalMuon::flush(timestamp_t, std::vector<TriggerCandidate>& output_tc)
{
  // Check the status of the current window, construct TC if conditions are met. Regardless
  // of whether the conditions are met, reset the window.
  if(m_current_window.adc_integral > m_adc_threshold && m_trigger_on_adc){
  //else if(m_current_window.adc_integral > m_conf.adc_threshold && m_conf.trigger_on_adc){
    //TLOG_DEBUG(TRACE_NAME) << "ADC integral in window is greater than specified threshold.";
    output_tc.push_back(construct_tc());
  }
  else if(m_current_window.n_channels_hit() > m_n_channels_threshold && m_trigger_on_n_channels){
  //else if(m_current_window.n_channels_hit() > m_conf.n_channels_threshold && m_conf.trigger_on_n_channels){
    //TLOG_DEBUG(TRACE_NAME) << "Number of channels hit in the window is greater than specified threshold.";
    output_tc.push_back(construct_tc());
  }

  //TLOG_DEBUG(TRACE_NAME) << "Clearing the current window, on the arrival of the next input_tp, the window will be
reset."; m_current_window.clear();

  return;
}*/
