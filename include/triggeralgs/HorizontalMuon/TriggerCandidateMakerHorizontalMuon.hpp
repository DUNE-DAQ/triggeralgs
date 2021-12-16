/**
 * @file TriggerCandidateMakerHorizontalMuon.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_HORIZONTALMUON_TRIGGERCANDIDATEMAKERHORIZONTALMUON_HPP_
#define TRIGGERALGS_HORIZONTALMUON_TRIGGERCANDIDATEMAKERHORIZONTALMUON_HPP_

#include "triggeralgs/TriggerCandidateMaker.hpp"

//#include "triggeralgs/triggercandidatemakerhorizontalmuon/Nljs.hpp"

#include <fstream>
#include <vector>

namespace triggeralgs {
class TriggerCandidateMakerHorizontalMuon : public TriggerCandidateMaker
{

public:
  /// The function that gets call when there is a new activity
  void operator()(const TriggerActivity&, std::vector<TriggerCandidate>&);
  
  void configure(const nlohmann::json &config);

  //void flush(timestamp_t, std::vector<TriggerCandidate>& output_tc);
  
private:
  class Window {
    public:
      bool is_empty() const{
        return ta_list.empty();
      };
      void add(const TriggerActivity &input_ta){
        // Add the input TA's contribution to the total ADC, increase the hit count
        // of all of the channels which feature and add it to the TA list keeping the TA
        // list time ordered by time_start. Preserving time order makes moving easier.
        adc_integral += input_ta.adc_integral;
        for(TriggerPrimitive tp : input_ta.tp_list) {
          channel_states[tp.channel]++;
        }
        // Perform binary search based on time_start.
        uint16_t insert_at = 0;
        for(auto ta : ta_list){
          if(input_ta.time_start < ta.time_start) break;
          insert_at++;
        }
        ta_list.insert(ta_list.begin()+insert_at, input_ta);
      };
      void clear(){
        ta_list.clear();
      };
      uint16_t n_channels_hit(){
        return channel_states.size();
      };
      void move(TriggerActivity const &input_ta, timestamp_t const &window_length){
        // Find all of the TAs in the window that need to be removed
        // if the input_ta is to be added and the size of the window 
        // is to be conserved.
        // Subtract those TAs' contribution from the total window ADC and remove their
        // contributions to the hit counts.
        uint32_t n_tas_to_erase = 0;
        for(auto ta : ta_list){
          if(!(input_ta.time_start-ta.time_start < window_length)){
            n_tas_to_erase++;
            adc_integral -= ta.adc_integral;
            for(TriggerPrimitive tp : ta.tp_list) {
              channel_states[tp.channel]--;
              // If a TA being removed from the window results in a channel no longer having
              // any hits, remove from the states map so map.size() can be used for number
              // channel hits.
              if(channel_states[tp.channel]==0) channel_states.erase(tp.channel);
            }
          }
          else break;
        }
        // Erase the TAs from the window.
        ta_list.erase(ta_list.begin(), ta_list.begin()+n_tas_to_erase);
        // Make the window start time the start time of what is now the
        // first TA.
        if(ta_list.size()!=0){
          time_start = ta_list.front().time_start;
          add(input_ta);
        }
        else add(input_ta);
      }
      void reset(TriggerActivity const &input_ta){
        // Empty the channel and TA lists.
        channel_states.clear();
        ta_list.clear();
        // Set the start time of the window to be the start time of the
        // input_ta.
        time_start = input_ta.time_start;
        // Start the total ADC integral.
        adc_integral = input_ta.adc_integral;
        // Start hit count for the hit channels.
        for(TriggerPrimitive tp : input_ta.tp_list) {
          channel_states[tp.channel]++;
        }
        // Add the input TA to the TA list.
        ta_list.push_back(input_ta);
      }
     friend std::ostream& operator<<(std::ostream& os, const Window& window){
        if(window.is_empty()) os << "Window is empty!\n";
  //      else{
  //        os << "Window start: " << window.time_start << ", end: " << window.ta_list.back().time_start;
  //        os << ". Total of: " << window.adc_integral << " ADC counts with " << window.ta_list.size() << " TPs.\n"; 
  //        os << window.channel_states.size() << " independent channels have hits.\n"; 
  //      }
        return os;
      };
    
      timestamp_t time_start;
      uint64_t adc_integral;
      std::unordered_map<channel_t,uint16_t> channel_states;
      std::vector<TriggerActivity> ta_list;
  };

  TriggerCandidate construct_tc() const;
  bool check_adjacency() const;

  Window m_current_window;
  uint64_t m_activity_count = 0; // NOLINT(build/unsigned)
  
  // Configurable parameters.
  // triggercandidatemakerhorizontalmuon::ConfParams m_conf;
  // If both m_trigger_on_adc and m_trigger_on_n_channels is false, nothing is done at
  // the candidate level, candidates are made 1 for 1 with activities.
  // Use any other combination of m_trigger_on_adc and m_trigger_on_n_channels with caution,
  // they have not been tested.
  bool m_trigger_on_adc = false;
  bool m_trigger_on_n_channels = false;
  uint32_t m_adc_threshold = 1200000;
  uint16_t m_n_channels_threshold = 600; // 80ish for frames, O(200 - 600) for tpslink
  timestamp_t m_window_length = 80000;
  int tc_number = 0;
  // Might not be the best type for this map.
  //std::unordered_map<std::pair<detid_t,channel_t>,channel_t> m_channel_map;

  // For debugging purposes.
  void add_window_to_record(Window window);
  void dump_window_record();
  std::vector<Window> m_window_record;

};
} // namespace triggeralgs

#endif // TRIGGERALGS_HORIZONTALMUON_TRIGGERCANDIDATEMAKERHORIZONTALMUON_HPP_