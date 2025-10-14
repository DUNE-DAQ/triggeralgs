#ifndef TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_
#define TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_

//#include "triggeralgs/BSMWindow/models/treelitemodel.h"
#include "triggeralgs/BSMWindow/treelitemodel.hpp"
#include <string>
#include <fstream>
#include <algorithm>

namespace triggeralgs {

// Interface for deploying XGBoost model using compiled C-code

  class TreeliteModelBase;

class CompiledModelInterface {
  public:

    CompiledModelInterface(int nbatch);

    ~CompiledModelInterface();

    //std::unique_ptr<TreeliteModelBase> GetModel() {
    //  return model_ptr;
    //}
    int GetNumFeatures(); //{
    //  return model_ptr->get_num_feature();
    //}

    void ModelWarmUp(Entry *input);

    void Predict(Entry *input, float *result);

    bool Classify(const float *result, float &bdt_threshold);

  protected:
    
    std::unique_ptr<TreeliteModelBase> model_ptr;
    int num_batch;

};
} // triggeralgs

#endif // TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_
