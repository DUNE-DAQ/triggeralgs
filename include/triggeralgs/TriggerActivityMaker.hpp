/**
 * @file TriggerActivityMaker.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITYMAKER_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITYMAKER_HPP_

#include "triggeralgs/Issues.hpp"
#include "triggeralgs/Logging.hpp"
#include "triggeralgs/TriggerActivity.hpp"
#include "triggeralgs/TriggerPrimitive.hpp"
#include "triggeralgs/Types.hpp"

#include <atomic>
#include <chrono>
#include <nlohmann/json.hpp>
#include <vector>

// TRACE_NAME to be defined in the derived TAMs
#include "TRACE/trace.h"

namespace triggeralgs {

class TriggerActivityMaker
{
public:
  virtual ~TriggerActivityMaker() = default;
  void operator()(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta)
  {
    // Apply TP filtering
    if (!preprocess(input_tp)) {
      return;
    }

    // Process TP, to implement per alg triggeralgs
    process(input_tp, output_ta);

    // Postprocess TA, e.g. prescaling
    postprocess(output_ta);
  }

  /**
   * @brief TP processing function that creates & fills TAs
   *
   * @param input_tp[in] Input TP for the triggering algorithm
   * @param output_ta[out] Output vector of TAs to fill by the algorithm
   */
  virtual void process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta) = 0;

  /**
   * @brief TP pre-processing/filtering
   *
   * Takes a TP and returns true or false depending whether we want to process
   * that TP into a TA algorithm.
   *
   * @todo: Implement tp-filtering, e.g. TOT, plane, channel and whatnot
   * @todo: Implement something smarter & more efficient if no filtering: vector of functions, or c-o-c
   *
   * @param[in] intput_tp input TP reference for filtering
   * @return bool true if we want to keep the TP
   */
  virtual bool preprocess(const TriggerPrimitive& input_tp)
  {
    if (input_tp.time_over_threshold > m_max_time_over_threshold) {
      return false;
    }

    return true;
  }

  /**
   * @brief Post-processing/filtering of the TAs, e.g. prescale
   *
   * Takes a vector of TAs and removes ones that we want to filter out, e.g.
   * based on prescaling.
   *
   * @todo: Like in preprocessing: implement something more efficient, e.g. vec of tasks
   *
   * @param output_ta[out] output triggeractivity vector
   */
  virtual void postprocess(std::vector<TriggerActivity>& output_ta)
  {
    // Don't post-process TAs if there's no TAs made.
    if (output_ta.size() == 0) {
      return;
    }

    // Apply prescale by erasing TAs
    if (m_prescale > 1) {
      for (std::vector<TriggerActivity>::iterator iter = output_ta.begin(); iter != output_ta.end();) {
        m_ta_count++;

        if (m_ta_count % m_prescale != 0) {
          iter = output_ta.erase(iter);
          continue;
        }

        TLOG(TLVL_DEBUG_10) << "Emitting prescaled TriggerActivity " << (m_ta_count-1)
                            << " with time start/end/activity: " << iter->time_start
                            << " " << iter->time_end << " " << iter->time_activity;
        ++iter;
      }
    }
  }

  virtual void flush(timestamp_t /* until */, std::vector<TriggerActivity>&) {}
  virtual void configure(const nlohmann::json& config) 
  {
    // Don't do anyting if the config does not exist
    if (!config.is_object()) {
      return;
    }

    if (config.contains("prescale"))
      m_prescale = config["prescale"];
    if (config.contains("max_time_over_threshold"))
      m_max_time_over_threshold = config["max_time_over_threshold"];

    TLOG() << "[TAM]: max tot   : " << m_max_time_over_threshold;
    TLOG() << "[TAM]: prescale  : " << m_prescale;
  }
  
  std::atomic<uint64_t> m_data_vs_system_time = 0;
  std::atomic<uint64_t> m_initial_offset = 0;

  /// @brief Configurable prescale factor
  uint64_t m_prescale = 1;
  /// @brief TA made count for prescaling
  uint64_t m_ta_count = 0;

  /// @brief Time-over-threshold TP filtering
  uint32_t m_max_time_over_threshold = std::numeric_limits<uint32_t>::max();
};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERACTIVITYMAKER_HPP_
