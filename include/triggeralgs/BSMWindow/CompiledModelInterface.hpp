#ifndef TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_
#define TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_

#include "triggeralgs/BSMWindow/models/treelite_compmodel_classifier_xgboost/treelitemodel.h"
#include <string>
#include <fstream>
#include <algorithm>

namespace triggeralgs {

// Interface for deploying XGBoost model using compiled C-code

class CompiledModelInterface {
  public:

    CompiledModelInterface(int nbatch);

    ~CompiledModelInterface();

    void ModelWarmUp(Entry *input);

    void Predict(Entry *input, float *result);

    bool Classify(const float *result, float &bdt_threshold);

  protected:

    int num_batch;

};
} // triggeralgs

#endif // TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_
