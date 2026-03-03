#ifndef TRIGGERALGS_TREELITEMODEL_HPP_
#define TRIGGERALGS_TREELITEMODEL_HPP_

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

#if defined(__clang__) || defined(__GNUC__)
#  define LIKELY(x)   __builtin_expect(!!(x), 1)
#  define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#  define LIKELY(x)   (x)
#  define UNLIKELY(x) (x)
#endif

namespace triggeralgs {

  union Entry {
    int missing;
    float fvalue;
    int qvalue;
  };

  /// Base class: defines shared interface and utilities for all models
  class TreeliteModelBase {
  public:
    TreeliteModelBase(int numTargets = 1, int maxNumClass = 1);
    virtual ~TreeliteModelBase() = default;

    int32_t get_num_target() const;
    void get_num_class(int32_t* out) const;
    // Different models may have different number of feature
    // - make this function virtual and always override it
    virtual int32_t get_num_feature() const = 0;

    virtual const char* get_threshold_type() const;
    virtual const char* get_leaf_output_type() const;

    //Virtual prediction function — overridden by each concrete model
    virtual void predict(union Entry* data, int pred_margin, float* result) const = 0;

    // Common postprocessing shared by all models
    virtual void postprocess(float* result) const;

    protected:
      static const int32_t num_class[1];
      int32_t N_TARGET;
      int32_t MAX_N_CLASS;
  };
  
  /// Model for signal finding in PD-HD — trained on PD-HD data
  class TreelitePDHDModel : public TreeliteModelBase {
  public:
    using TreeliteModelBase::TreeliteModelBase;
    virtual int32_t get_num_feature() const override;
    void predict(union Entry* data, int pred_margin, float* result) const override;
  };

  // Add model later for PD-VD signal findings

} // namespace triggeralgs
#endif // TRIGGERALGS_TREELITEMODEL_HPP_
