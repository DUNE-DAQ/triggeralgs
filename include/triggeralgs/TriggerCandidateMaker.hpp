/**
 * @file TriggerCandidateMaker.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_
#define TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_

#include "triggeralgs/Issues.hpp"
#include "triggeralgs/Logging.hpp"
#include "triggeralgs/TriggerActivity.hpp"
#include "triggeralgs/TriggerCandidate.hpp"
#include "triggeralgs/Types.hpp"

#include <atomic>
#include <chrono>
#include <nlohmann/json.hpp>
#include <vector>

// TRACE_NAME to be defined in the derived TAMs
#include "TRACE/trace.h"

namespace triggeralgs {

class TriggerCandidateMaker
{
public:
  virtual ~TriggerCandidateMaker() = default;
  void operator()(const TriggerActivity& input_ta, std::vector<TriggerCandidate>& output_tc)
  {
    // Apply TP filtering
    if (!preprocess(input_ta)) {
      return;
    }

    // Process TP, to implement per alg triggeralgs
    process(input_ta, output_tc);

    // Postprocess TA, e.g. prescaling
    postprocess(output_tc);
  }

  /**
   * @brief TA processing function that creates & fills TCs
   *
   * @param input_ta[in] Input TA for the triggering algorithm
   * @param output_tc[out] Output vector of TCs to fill by the algorithm
   */
  virtual void process(const TriggerActivity& input_ta, std::vector<TriggerCandidate>& output_tc) = 0;

  /**
   * @brief TA pre-processing/filtering
   *
   * @todo: Implement ta-filtering, e.g. by plane or sub-detector
   * @todo: Implement something smarter & more efficient if no filtering: vector of functions, or c-o-c
   *
   * @param[in] intput_tp input TP reference for filtering
   * @return bool true if we want to keep the TP
   */
  virtual bool preprocess(const TriggerActivity&)
  {
    return true;
  }

  /**
   * @brief Post-processing/filtering of the TCs, e.g. prescale
   *
   * Takes a vector of TCs and removes ones that we want to filter out, e.g.
   * based on prescaling.
   *
   * @todo: Like in preprocessing: implement something more efficient, e.g. vec of tasks
   *
   * @param output_tc[out] output trigger candidate vector
   */
  virtual void postprocess(std::vector<TriggerCandidate>& output_tc)
  {
    // Don't post-process TCs if there's no TCs made.
    if (output_tc.size() == 0) {
      return;
    }

    // Apply prescale by erasing TCs
    if (m_prescale > 1) {
      for (std::vector<TriggerCandidate>::iterator iter = output_tc.begin(); iter != output_tc.end();) {
        m_tc_count++;

        if (m_tc_count % m_prescale != 0) {
          iter = output_tc.erase(iter);
          continue;
        }

        TLOG_DEBUG(TLVL_DEBUG_10) << "Emitting prescaled TriggerCandidate " << (m_tc_count-1);
        ++iter;
      }
    }
  }
  virtual void flush(timestamp_t /* until */, std::vector<TriggerCandidate>& /* output_tc */) {}
  virtual void configure(const nlohmann::json& config)
  {
    // Don't do anyting if the config does not exist
    if (!config.is_object()) {
      return;
    }

    if (config.contains("prescale")) {
      m_prescale = config["prescale"];
    }

    if (config.contains("tc_type_name")) {
      m_tc_type_out = static_cast<TriggerCandidate::Type>(
          dunedaq::trgdataformats::string_to_trigger_candidate_type(config["tc_type_name"]));
    }

    if (m_tc_type_out == TriggerCandidate::Type::kUnknown) {
      throw(InvalidConfiguration(ERS_HERE, "Provided an unknown output TC type: "
              + std::string(config["tc_type_name"])));
    }

    TLOG() << "[TCM]: prescale   : " << m_prescale;
    TLOG() << "[TCM]: TC type out: " << config["tc_type_name"];
  }

  std::atomic<uint64_t> m_data_vs_system_time = 0;
  std::atomic<uint64_t> m_initial_offset = 0;  

  /// @brief Configurable prescale factor
  uint64_t m_prescale = 1;
  /// @brief TC made count for prescaling
  uint64_t m_tc_count = 0;

  /// @brief Configurable TC type output
  TriggerCandidate::Type m_tc_type_out = TriggerCandidate::Type::kUnknown;

};

} // namespace triggeralgs

#endif // TRIGGERALGS_INCLUDE_TRIGGERALGS_TRIGGERCANDIDATEMAKER_HPP_
