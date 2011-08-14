#ifndef _UTILITY_H
#define _UTILITY_H

#include <boost/unordered_map.hpp>

typedef boost::unordered_map<std::string, std::string> options_map;

class Utility {
 public:
  static std::string trim(std::string);
};

#endif
