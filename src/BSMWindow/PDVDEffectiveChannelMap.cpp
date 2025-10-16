#include "triggeralgs/BSMWindow/PDVDEffectiveChannelMap.hpp"

namespace triggeralgs {

PDVDEffectiveChannelMap::PDVDEffectiveChannelMap(unsigned int first_channel, unsigned int n_channels) :
  m_first_channel(first_channel), m_n_channels(n_channels) {

  m_n_channels_crp_block = m_n_channels / 4; // four crps in a plane, should = 292
  m_n_effective_channels = m_n_channels / 2; // # effective channels half # true channels, should = 584
}

unsigned int PDVDEffectiveChannelMap::remapCollectionPlaneChannel(unsigned int original_channel) {
  // subtract first channel on CRP from original_channel
  // add first channel back at the end
  unsigned int sub_original_channel = original_channel - m_first_channel;
  
  const unsigned int crp_block = sub_original_channel / m_n_channels_crp_block; // 0..3
  
  const unsigned int local_channel = sub_original_channel % m_n_channels_crp_block; // 0..291
  
  // get the base channel based on which CRP block the originial channel is in
  const unsigned int base_channel  = (crp_block >= 2) ? m_n_channels_crp_block : 0;
  
  // remapped channel is the base plus the local channel in the block
  // and plus the first channel in the CRP plane
  return base_channel + local_channel + m_first_channel;
}

} // triggeralgs
