#include "triggeralgs/BSMWindow/CompiledModelInterface.hpp"

#include <iostream>

namespace triggeralgs {

CompiledModelInterface::CompiledModelInterface(int nbatch) : num_batch(nbatch) {}

CompiledModelInterface::~CompiledModelInterface() {}

void CompiledModelInterface::ModelWarmUp(Entry *input) {
  // Warm the BDT up here
  float result[num_batch];
  for (int rid = 0; rid < num_batch; ++rid) {
    for (int i = 0; i < 100; i++) {
      predict(input, 0, result);
    }
  }
}

void CompiledModelInterface::Predict(Entry *input, float *result) {
  for (int rid = 0; rid < num_batch; ++rid) {
    predict(input, 0, result);
  }
}

bool CompiledModelInterface::Classify(const float *result, float &bdt_threshold) {
  for (uint64_t rid = 0; rid < num_batch; rid++) {
    if (result[rid] > bdt_threshold) {
      return true;
    }
  }
  return false;
}


} // namespace triggeralgs
