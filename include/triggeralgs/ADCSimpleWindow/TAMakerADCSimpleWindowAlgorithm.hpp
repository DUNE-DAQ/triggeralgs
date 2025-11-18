/**
 * @file TAMakerADCSimpleWindowAlgorithm.hpp
 *
 * This is part of the DUNE DAQ Application Framework, copyright 2021.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#ifndef TRIGGERALGS_ADCSIMPLEWINDOW_TRIGGERACTIVITYMAKERADCSIMPLEWINDOW_HPP_
#define TRIGGERALGS_ADCSIMPLEWINDOW_TRIGGERACTIVITYMAKERADCSIMPLEWINDOW_HPP_

#include "triggeralgs/TriggerActivityFactory.hpp"
#include "triggeralgs/Types.hpp"

#include <deque>

namespace triggeralgs {
class TAMakerADCSimpleWindowAlgorithm : public TriggerActivityMaker
{

public:
  void process(const TriggerPrimitive& input_tp, std::vector<TriggerActivity>& output_ta);
  
  void configure(const nlohmann::json &config);

  class Window {
    public:
      friend std::ostream& operator<<(std::ostream& os, const Window& window);

      bool is_empty() const{
        return tp_list.empty();
      };
    
      void add(TriggerPrimitive const &input_tp);

      void clear(){
        tp_list.clear();
      };
      
      void move(TriggerPrimitive const &input_tp, timestamp_t const &window_length);

      void reset(TriggerPrimitive const &input_tp);

      timestamp_t time_start;
      uint32_t adc_integral;
      std::deque<TriggerPrimitive> tp_list;
  };

private:  

  TriggerActivity construct_ta() const;

  Window m_current_window;
  uint64_t m_primitive_count = 0;

  // Configurable parameters.
  uint32_t m_adc_threshold = 1200000;
  timestamp_t m_window_length = 100000;
};


} // namespace triggeralgs

#endif // TRIGGERALGS_ADCSIMPLEWINDOW_TRIGGERACTIVITYMAKERADCSIMPLEWINDOW_HPP_
