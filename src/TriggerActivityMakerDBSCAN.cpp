/**
 * @file TriggerActivityMakerDBSCAN.cpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "triggeralgs/dbscan/TriggerActivityMakerDBSCAN.hpp"
#include "dbscan/Point.hpp"

#include "TRACE/trace.h"
#include "triggeralgs/Types.hpp"
#include <chrono>
#include <limits>
#define TRACE_NAME "TriggerActivityMakerDBSCAN"

#include <vector>

using namespace triggeralgs;

void
TriggerActivityMakerDBSCAN::operator()(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta)
{
  // Collection channels only for now
  if(input_tp.channel%2560 < 1600){
    return;
  }
  
  if(input_tp.time_start < m_prev_timestamp){
    TLOG(TLVL_INFO) << "Out-of-order TPs: prev " << m_prev_timestamp << ", current " << input_tp.time_start;
    return;
  }
  
  m_dbscan_clusters.clear();
  m_dbscan->add_primitive(input_tp, &m_dbscan_clusters);

  // if(!m_dbscan_clusters.empty()){
  //   TLOG(TLVL_DEBUG) << "Got " << m_dbscan_clusters.size() << " clusters";
  // }

  uint64_t t0=m_dbscan->get_first_prim_time();
  
  // for(auto const& cluster : m_dbscan_clusters){
  //   auto& ta=output_ta.emplace_back();

  //   ta.time_start = std::numeric_limits<timestamp_t>::max();
  //   ta.time_end = 0;
  //   ta.channel_start = std::numeric_limits<channel_t>::max();
  //   ta.channel_end = 0;
  //   ta.adc_integral =  0;
    
  //   for(auto const& hit : cluster.hits){
  //     timestamp_t hit_timestamp=t0+static_cast<timestamp_t>(hit->time);
  //     ta.time_start = std::min(hit_timestamp, ta.time_start);
  //     ta.time_end = std::max(hit_timestamp, ta.time_end);

  //     ta.channel_start = std::min(hit->chan, ta.channel_start);
  //     ta.channel_end = std::max(hit->chan, ta.channel_end);
  //   }
    
  //   ta.time_peak = (ta.time_start+ta.time_end)/2;
  //   ta.time_activity = ta.time_peak;

  //   ta.channel_peak = (ta.channel_start+ta.channel_end)/2;

  //   ta.type = TriggerActivity::Type::kTPC;
  //   ta.algorithm = TriggerActivity::Algorithm::kDBSCAN;
  //   ta.version = 1;

  // }

  for(auto const& cluster : m_dbscan_clusters){
    auto& ta=output_ta.emplace_back();

    ta.time_start = std::numeric_limits<timestamp_t>::max();
    ta.time_end = 0;
    ta.channel_start = std::numeric_limits<channel_t>::max();
    ta.channel_end = 0;
    ta.adc_integral =  0;
    
    for(auto const& hit : cluster.hits){
      auto const& prim=hit->primitive;

      ta.tp_list.push_back(prim);
      
      ta.time_start = std::min(prim.time_start, ta.time_start);
      ta.time_end = std::max(prim.time_start + prim.time_over_threshold, ta.time_end);

      ta.channel_start = std::min(prim.channel, ta.channel_start);
      ta.channel_end = std::max(prim.channel, ta.channel_end);

      ta.adc_integral += prim.adc_integral;

      ta.detid = prim.detid;
    }
    
    ta.time_peak = (ta.time_start+ta.time_end)/2;
    ta.time_activity = ta.time_peak;

    ta.channel_peak = (ta.channel_start+ta.channel_end)/2;

    ta.type = TriggerActivity::Type::kTPC;
    ta.algorithm = TriggerActivity::Algorithm::kDBSCAN;
    ta.version = 1;

  }

  m_dbscan->trim_hits();
}

void
TriggerActivityMakerDBSCAN::configure(const nlohmann::json &config)
{
  if (config.is_object() && config.contains("min_pts"))
  {
    m_min_pts = config["min_pts"];
  }

  m_dbscan=std::make_unique<dbscan::IncrementalDBSCAN>(10, m_min_pts);
}
