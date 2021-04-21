#include "triggeralgs/Supernova/TriggerDecisionMaker_Supernova.hpp"

#include <algorithm>
#include <limits>
#include <chrono>

using pd_clock = std::chrono::duration<double, std::ratio<1, 50000000>>;
using namespace triggeralgs;

void TriggerDecisionMakerSupernova::operator()(const TriggerCandidate& cand,
                                               std::vector<TriggerDecision>& decisions) {

  std::vector<TriggerCandidate> vCand;
  vCand.push_back(cand);
  
  auto now = std::chrono::steady_clock::now();
//  Timestamp 
  uint32_t algorithm = (uint32_t)pd_clock(now.time_since_epoch()).count();

  TriggerDecision trigger {cand.time_start,
                           cand.time_end,
                           cand.time_candidate,
			   0,
                           0,
                           0,
                           //cand.detid,
                           0,
                           algorithm,
                           cand.version,
                           vCand}; 

    // Give the trigger word back
    decisions.push_back(trigger);
    return;
}