#include "triggeralgs/BSMWindow/treelitemodel.hpp"

namespace triggeralgs {

// Implement functions of TreeliteModelBase base class
// that are common to all compiled GBDT models

const int32_t TreeliteModelBase::num_class[1] = { 1 };

TreeliteModelBase::TreeliteModelBase(int numTargets, int maxNumClass)
  : N_TARGET(numTargets), MAX_N_CLASS(maxNumClass) {}

int32_t TreeliteModelBase::get_num_target(void) const {
  return N_TARGET;
}

void TreeliteModelBase::get_num_class(int32_t* out) const {
  for (int i = 0; i < N_TARGET; ++i) {
    out[i] = TreeliteModelBase::num_class[i];
  }
}

const char* TreeliteModelBase::get_threshold_type(void) const {
  return "float32";
}
const char* TreeliteModelBase::get_leaf_output_type(void) const {
  return "float32";
}

void TreeliteModelBase::postprocess(float* result) const {
  // sigmoid
  const float alpha = (float)1;
  for (size_t i = 0; i < N_TARGET * MAX_N_CLASS; ++i) {
    result[i] = (float)(1) / ((float)(1) + expf(-alpha * result[i]));
  }
}

} // end namespace triggeralgs
