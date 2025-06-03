#ifndef TRIGGERALGS_TREELITEMODELINTERFACE_HPP_
#define TRIGGERALGS_TREELITEMODELINTERFACE_HPP_

#include <treelite/c_api.h>

#include <string>
#include <fstream>
#include <algorithm>

#define safe_treelite(call) {  \
  int err = (call); \
  if (err != 0) { \
    throw std::runtime_error(std::string(__FILE__) + ":" + std::to_string(__LINE__) + \
      ": error in " + #call + ":" + TreeliteGetLastError());  \
  } \
}

namespace triggeralgs {

// Interface for deploying XGBoost model using Treelite

class TreeliteModelInterface {
  public:

    TreeliteModelInterface(const char* model_path, int &batch_size);

    ~TreeliteModelInterface();

    void ModelWarmUp(float *input);

    void Predict(float *input, float *result);

    bool Classify(const float *result, float &bdt_threshold);

    uint64_t GetShapeElement(int i) {
      if (i < 0 || i > 2) return treelite_out_shape[0];
      return treelite_out_shape[i];
    }

  protected:

    TreeliteModelHandle treelite_model;
    TreeliteGTILConfigHandle treelite_config;
    const uint64_t *treelite_out_shape;
    uint64_t treelite_out_ndim; 

};
} // triggeralgs

#endif // TRIGGERALGS_TREELITEMODELINTERFACE_HPP_
