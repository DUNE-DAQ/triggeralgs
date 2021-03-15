#pragma once
#include "dune-trigger-algs/TriggerCandidateMaker_Timing.hh"

#include <algorithm>
#include <limits>
#include <atomic>
#include <utility>


namespace triggeralgs {
  class TriggerCandidateMakerTiming: public TriggerCandidateMaker_Timing {
    /// This decision maker just counts the number of activities in the time_window and triggers
    /// if the number of activities exceeds that.
    
  public:
    /// The function that gets call when there is a new primitive 
    void operator()(const TriggerPrimitive&, std::vector<TriggerCandidate>&);
    
  protected:
    std::vector<TriggerPrimitive> m_primitive;
    std::atomic<int64_t > m_time_window   = {500'000'000};   /// Slinding time window to count activities
    // example values
    std::vector<std::pair<int64_t, int64_t>> m_map = { {1000,2000}, {10000, 20000}, {5000000, 600000} };

    /// this function gets rid of the old activities
    void FlushOldActivity(int64_t time_now) {
      int64_t how_far = time_now - m_time_window;
      auto end = std::remove_if(m_primitive.begin(), m_primitive.end(),
				[how_far, this] (auto& c) -> bool {
				  return (c.time_start<how_far);
				});
      m_primitive.erase(end, m_primitive.end());
    }
  };
}