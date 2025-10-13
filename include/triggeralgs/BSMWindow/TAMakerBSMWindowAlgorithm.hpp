/**
 * @file TAMakerBSMWindowAlgorithm.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_BSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_
#define TRIGGERALGS_BSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_

#include "detchannelmaps/TPCChannelMap.hpp"
#include "triggeralgs/TriggerActivityFactory.hpp"
#include "triggeralgs/Types.hpp"
#include "triggeralgs/BSMWindow/BSMWindow.hpp"
#include "triggeralgs/BSMWindow/CompiledModelInterface.hpp"

#include <fstream>
#include <vector>
#include <algorithm>

namespace triggeralgs {
class TAMakerBSMWindowAlgorithm : public TriggerActivityMaker
{

public:
  void process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta); 
  void configure(const nlohmann::json &config);

  ~TAMakerBSMWindowAlgorithm() override;

private:
  // Function to handle XGBoost classification
  // Returns true for signal and false for cosmic
  bool compute_treelite_classification();

  TriggerActivity construct_ta() const;

  // The current time window of TPs
  BSMWindow m_current_window;

  timestamp_t m_last_pred_time;
  uint64_t m_primitive_count = 0;

  // Possible to do batch predictions with XGBoost
  // For now just keep at 1
  const int nbatch = 1;
  // XGBoost takes a row-major flat array
  std::vector<float> flat_batched_inputs;
  // row-major input for Entry objects used for compiled model
  std::vector<Entry> flat_batched_Entries;

  // Configurable parameters.
  uint32_t m_adc_threshold = 200000;
  float m_ratio_threshold = 0.65;
  float m_bdt_threshold = 0.99;
  timestamp_t m_window_length = 20000;

  // Define time binning
  timestamp_t m_bin_length = 4000;
  int m_num_timebins = 5;
  // Define channel binning
  channel_t m_chan_bin_length = 100;
  int m_num_chanbins = 5;

  // Extract plane channel range information
  // from csv files. Necessary for binning in channel ID
  // (May find a neater way to do this in the future.)
  struct PlaneInfo {
    int min_channel;
    int n_channels;
  };

  const std::map<std::pair<int,int>, PlaneInfo> pdhd_plane_map = {
    {{0,0}, {400,400}}, 
    {{0,1}, {1200,400}}, 
    {{0,2}, {2080,480}},
    {{1,0}, {2560,400}}, 
    {{1,1}, {3360,400}}, 
    {{1,2}, {4160,480}},
    {{2,0}, {5520,400}}, 
    {{2,1}, {6320,400}}, 
    {{2,2}, {7200,480}},
    {{3,0}, {7680,400}}, 
    {{3,1}, {8480,400}}, 
    {{3,2}, {9280,480}}
  };

  const std::map<std::pair<int,int>, PlaneInfo> pdvd_plane_map = {
    {{2,0}, { 6144,  952}},
    {{2,1}, { 7096,  952}},
    {{2,2}, { 8048, 1168}},
    {{3,0}, { 9216,  952}},
    {{3,1}, {10168,  952}},
    {{3,2}, {11120, 1168}},
    {{4,0}, { 3072,  952}},
    {{4,1}, { 4024,  952}},
    {{4,2}, { 4976, 1168}},
    {{5,0}, {    0,  952}},
    {{5,1}, {  952,  952}},
    {{5,2}, { 1904, 1168}}
  };

  // Function to get the plane range map information. The detid controls 
  // whether to use the PD-HD or PD-VD map
  PlaneInfo get_plane_info(int detid, int detelement, int plane);

  // Geometry information for binning
  std::string m_channel_map_name = "PD2VDTPCChannelMap";
  std::shared_ptr<dunedaq::detchannelmaps::TPCChannelMap> channelMap = 
    dunedaq::detchannelmaps::make_tpc_map(m_channel_map_name);
  channel_t m_first_channel;
  channel_t m_last_channel;

  // Compiled treelite model interface
  std::unique_ptr<CompiledModelInterface> m_compiled_model_interface;

};
} // namespace triggeralgs

#endif // TRIGGERALGS_BSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_
