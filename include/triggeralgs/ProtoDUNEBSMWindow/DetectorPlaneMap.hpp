
#ifndef TRIGGERALGS_PROTODUNEBSMWINDOW_DETECTORPLANEMAP_HPP_
#define TRIGGERALGS_PROTODUNEBSMWINDOW_DETECTORPLANEMAP_HPP_

#include <string>
#include <map>
#include <algorithm>

namespace triggeralgs {

  struct PlaneInfo {
    int min_channel;
    int n_channels;
  };

  // Provides mapping of plane and TPC ID to the first channel 
  // and number of channels on that plane
  struct DetectorPlaneMap {
    const std::map<std::pair<int,int>, PlaneInfo> pdhd_plane_map = {
      {{0,0}, {400,400}}, 
      {{0,1}, {1200,400}}, 
      {{0,2}, {2080,480}},
      {{1,0}, {2560,400}}, 
      {{1,1}, {3360,400}}, 
      {{1,2}, {4160,480}},
      {{2,0}, {5520,400}}, 
      {{2,1}, {6320,400}}, 
      {{2,2}, {7200,480}},
      {{3,0}, {7680,400}}, 
      {{3,1}, {8480,400}}, 
      {{3,2}, {9280,480}}
    };

    const std::map<std::pair<int,int>, PlaneInfo> pdvd_plane_map = {
      {{2,0}, { 6144,  952}},
      {{2,1}, { 7096,  952}},
      {{2,2}, { 8048, 1168}},
      {{3,0}, { 9216,  952}},
      {{3,1}, {10168,  952}},
      {{3,2}, {11120, 1168}},
      {{4,0}, { 3072,  952}},
      {{4,1}, { 4024,  952}},
      {{4,2}, { 4976, 1168}},
      {{5,0}, {    0,  952}},
      {{5,1}, {  952,  952}},
      {{5,2}, { 1904, 1168}}
    };

    // Function to get the plane range map information. The detid controls 
    // whether to use the PD-HD or PD-VD map
    PlaneInfo get_plane_info(std::string channel_map_name, int detelement, int plane);
  };
} // triggeralgs
#endif
