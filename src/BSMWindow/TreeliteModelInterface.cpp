#include "triggeralgs/BSMWindow/TreeliteModelInterface.hpp"

#include <iostream>

namespace triggeralgs {

TreeliteModelInterface::TreeliteModelInterface(const char* model_path, int &batch_size) {
  const char* predict_cfg = 
    "{\"predict_type\":\"default\","
    "\"nthread\":1}";
    
    safe_treelite(TreeliteLoadXGBoostModelJSON(model_path, predict_cfg, &treelite_model));

    safe_treelite(TreeliteGTILParseConfig(predict_cfg, &treelite_config));

    safe_treelite(TreeliteGTILGetOutputShape(treelite_model, (uint64_t)batch_size, treelite_config, &treelite_out_shape, &treelite_out_ndim));

    std::cout << "Treelite Model Shape: (";
    for (uint64_t i = 0; i < treelite_out_ndim; i++) {
      std::cout << treelite_out_shape[i] << ", ";
    }
    std::cout << ")\n";

    std::cout << "Treelite Model dim: " << treelite_out_ndim << std::endl;

    if (treelite_out_shape[0] != (uint64_t)batch_size) {
      std::cerr << "[ERROR] output shape should match the number of batches." << std::endl;
      exit(1);
    }
}

TreeliteModelInterface::~TreeliteModelInterface() {
  TreeliteFreeModel(treelite_model);
}

void TreeliteModelInterface::ModelWarmUp(float *input) {
  // Warm the BDT up here
  std::string input_type = "float32";
  float result[treelite_out_shape[0]];
    
  for (int i = 0; i < 10; i++) {
    safe_treelite(TreeliteGTILPredict(
          treelite_model,
          input,
          input_type.c_str(),
          treelite_out_shape[0],
          result,
          treelite_config
          ));
  }
}

void TreeliteModelInterface::Predict(float *input, float *result) {
  
  std::string input_type = "float32";

  safe_treelite(TreeliteGTILPredict(
        treelite_model,
        input,
        input_type.c_str(),
        treelite_out_shape[0],
        result,
        treelite_config
        ));
}

bool TreeliteModelInterface::Classify(const float *result, float &bdt_threshold) {
  for (uint64_t i = 0; i < treelite_out_shape[0]; i++) {
    std::cout << "BDT output = " << result[i] << "\n";
    if (result[i] > bdt_threshold) {
      return true;
    }
  }
  return false;
}


} // namespace triggeralgs
