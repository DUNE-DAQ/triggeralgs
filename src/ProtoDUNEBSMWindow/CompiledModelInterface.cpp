#include "triggeralgs/ProtoDUNEBSMWindow/CompiledModelInterface.hpp"

#include <iostream>

namespace triggeralgs {

CompiledModelInterface::CompiledModelInterface(int nbatch, bool is_pdvd) : num_batch(nbatch) {
  if (is_pdvd) {  
    model_ptr = std::make_unique<TreelitePDVDModel>();
  } else {
    model_ptr = std::make_unique<TreelitePDHDModel>();
  }
}

CompiledModelInterface::~CompiledModelInterface() {}
    
int CompiledModelInterface::GetNumFeatures() {
  return model_ptr->get_num_feature();
}

void CompiledModelInterface::Predict(Entry *input, float *result) {
  for (int rid = 0; rid < num_batch; ++rid) {
    model_ptr->predict(input, 0, result);
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
