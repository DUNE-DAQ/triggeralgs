/**
 * @file TAMakerProtoDUNEBSMWindowAlgorithm.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_PROTODUNEBSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_
#define TRIGGERALGS_PROTODUNEBSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_

#include "detchannelmaps/TPCChannelMap.hpp"
#include "triggeralgs/TriggerActivityFactory.hpp"
#include "triggeralgs/Types.hpp"
#include "triggeralgs/ProtoDUNEBSMWindow/ProtoDUNEBSMWindow.hpp"
#include "triggeralgs/ProtoDUNEBSMWindow/CompiledModelInterface.hpp"
#include "triggeralgs/ProtoDUNEBSMWindow/DetectorPlaneMap.hpp"
#include "triggeralgs/ProtoDUNEBSMWindow/PDVDEffectiveChannelMap.hpp"

#include <vector>
#include <algorithm>

namespace triggeralgs {
class TAMakerProtoDUNEBSMWindowAlgorithm : public TriggerActivityMaker
{

public:
  void process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta); 
  void configure(const nlohmann::json &config);

  ~TAMakerProtoDUNEBSMWindowAlgorithm() override;

private:
  // Function to handle XGBoost classification
  // Returns true for signal and false for cosmic
  bool compute_treelite_classification();

  TriggerActivity construct_ta() const;
  
  // The current time window of TPs
  ProtoDUNEBSMWindow m_current_window;

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
  uint32_t m_adc_threshold_induction = 12000000;
  float m_bdt_threshold = 0.99;
  std::string m_channel_map_name = "PD2VDTPCChannelMap";
  // End of configurable parameters
  
  // Constant parameters defined by XGBoost model training
  // Currently both PD-HD and PD-VD XGBoost models have been trained
  // on data filtered to have an ADC sum > 200k ADC
  const uint32_t m_adc_threshold_collection = 200000;
  const timestamp_t m_window_length = 20000;
  // End constant parameters

  // Define time binning
  timestamp_t m_bin_length = 2000;
  // Number of bins fixed by model training
  const int m_num_timebins = 10;
  // Define channel binning
  channel_t m_chan_bin_length = 50;
  // Number of bins fixed by model training
  const int m_num_chanbins = 10;

  // Geometry information for binning
  std::shared_ptr<dunedaq::detchannelmaps::TPCChannelMap> channelMap; 
  // First channel in each plane and number of channels
  // in a plane not in channel map by default, so add 
  // a struct to access these values
  DetectorPlaneMap m_det_plane_map;
  // In PD-VD want to work with effective offline channel
  // rather than the true offline channel. Have an object that helps
  // to do this. It prevents gaps in channel vs time images
  std::unique_ptr<PDVDEffectiveChannelMap> m_pdvd_eff_channel_mapper = nullptr;
  // If in NP02 and using a PD-VD channel map, set this to true
  bool m_pdvd_map = true;
  // Only use the XGBoost model if we are looking at collection plane TPs
  bool m_collection_plane = false;
  // first and last channel on the plane
  channel_t m_first_channel;
  channel_t m_last_channel;

  // Compiled treelite model interface
  std::unique_ptr<CompiledModelInterface> m_compiled_model_interface;

};
} // namespace triggeralgs

#endif // TRIGGERALGS_PROTODUNEBSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_
