#ifndef TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_
#define TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_

#include "triggeralgs/ProtoDUNEBSMWindow/treelitemodel.hpp"
#include <string>
#include <fstream>
#include <algorithm>

namespace triggeralgs {

// Interface for deploying XGBoost model using compiled C-code
// XGBoost model converted to treelite and then converted to c-code

// Foward declare base class for the treelite model
class TreeliteModelBase;

class CompiledModelInterface {
  public:

    CompiledModelInterface(int nbatch, bool is_pdvd);

    ~CompiledModelInterface();

    // Get number of features in model 
    int GetNumFeatures();

    // Run prediction with GBDT
    void Predict(Entry *input, float *result);

    // Is it a neutrino or cosmic according to GBDT?
    bool Classify(const float *result, float bdt_threshold);

  protected:
    
    std::unique_ptr<TreeliteModelBase> model_ptr;
    int num_batch;

};
} // triggeralgs

#endif // TRIGGERALGS_COMPILEDMODELINTERFACE_HPP_
