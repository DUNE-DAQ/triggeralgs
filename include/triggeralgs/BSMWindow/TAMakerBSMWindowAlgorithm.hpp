/**
 * @file TAMakerBSMWindowAlgorithm.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_BSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_
#define TRIGGERALGS_BSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_

#include "triggeralgs/TriggerActivityFactory.hpp"
#include "triggeralgs/Types.hpp"
#include "triggeralgs/BSMWindow/WindowBin.hpp"
#include "triggeralgs/BSMWindow/BinnedWindow.hpp"
#include "triggeralgs/BSMWindow/TreeliteModelInterface.hpp"

#include <fstream>
#include <vector>
#include <algorithm>

#define safe_treelite(call) {  \
  int err = (call); \
  if (err != 0) { \
    throw std::runtime_error(std::string(__FILE__) + ":" + std::to_string(__LINE__) + \
      ": error in " + #call + ":" + TreeliteGetLastError());  \
  } \
}

namespace triggeralgs {
class TAMakerBSMWindowAlgorithm : public TriggerActivityMaker
{

public:
  void process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta); 
  void configure(const nlohmann::json &config);

  ~TAMakerBSMWindowAlgorithm() override;

private:

  bool compute_treelite_classification();

  TriggerActivity construct_ta() const;

  BinnedWindow m_current_window;
  WindowBin m_current_bin;
  uint64_t m_primitive_count = 0;

  // Try batching the input - introduce some latency,
  // but maybe speed up the algorithm
  int nbatch = 1;
  // BDT batching takes a row-major flat array
  std::vector<float> flat_batched_inputs;
  // Keep track of the number of windows in the current batch
  int nbatch_iterator = 0;

  // Configurable parameters.
  uint32_t m_adc_threshold = 1200000;
  float m_bdt_threshold = 0.95;
  timestamp_t m_window_length = 20000;
  // now the length of the bin
  timestamp_t m_bin_length = 1000;
  int nbins = 20;
  int m_algtype = 0;

  // Treelite model
  std::unique_ptr<TreeliteModelInterface> m_treelite_model_interface;

};
} // namespace triggeralgs

#endif // TRIGGERALGS_BSMWINDOW_TRIGGERACTIVITYMAKERBSMWINDOW_HPP_
