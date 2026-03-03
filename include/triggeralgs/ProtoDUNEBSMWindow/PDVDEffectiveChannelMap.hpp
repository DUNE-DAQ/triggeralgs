
#ifndef TRIGGERALGS_PROTODUNEBSMWINDOW_PDVDEFFECTIVECHANNELMAP_HPP_
#define TRIGGERALGS_PROTODUNEBSMWINDOW_PDVDEFFECTIVECHANNELMAP_HPP_

namespace triggeralgs {

  // Class to provide mapping from true channel to effective channel 
  // in PD-VD. This is due to the non-intuitive true channel mapping
  // of CRP planes that makes image creation challenging. Effective 
  // channel mapping avoids gaps in the images
  class PDVDEffectiveChannelMap {
    public:
      PDVDEffectiveChannelMap(unsigned int first_channel, unsigned int n_channels);

      // Function to do mapping from true -> effective channel
      unsigned int remapCollectionPlaneChannel(unsigned int original_channel);

      // Number of effective channels on CRP will be 1/2 number of true channels
      unsigned int getNEffectiveChannels() { return m_n_effective_channels; }

    protected:
      
      unsigned int m_first_channel;
      unsigned int m_n_channels;
      unsigned int m_n_channels_crp_block;
      unsigned int m_n_effective_channels;

  };

} // triggeralgs
#endif
