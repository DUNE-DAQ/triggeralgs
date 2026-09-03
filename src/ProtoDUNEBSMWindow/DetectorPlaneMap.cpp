#include "triggeralgs/ProtoDUNEBSMWindow/DetectorPlaneMap.hpp"
#include <stdexcept>

namespace triggeralgs {

PlaneInfo DetectorPlaneMap::get_plane_info(std::string channel_map_name, int detelement, int plane) {

  const std::map<std::pair<int,int>, PlaneInfo> *plane_map;
  if (channel_map_name == "PD2HDTPCChannelMap") plane_map = &pdhd_plane_map;
  else if (channel_map_name == "PD2VDTPCChannelMap" ||
           channel_map_name == "PD2VDBottomTPCChannelMap" ||
           channel_map_name == "PD2VDTopTPCChannelMap") plane_map = &pdvd_plane_map;
  else throw std::invalid_argument("Unknown channel map: " + channel_map_name);

  auto it = plane_map->find({detelement, plane});
  if (it == plane_map->end()) {
    throw std::out_of_range("Invalid detelement/plane combination");
  }
  return it->second;
}

} // triggeralgs
