#include "Summoner.h"
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#ifndef POO_INCLUDE_CLIENT_H_
#define POO_INCLUDE_CLIENT_H_

class Client {
 public:
  Client(const std::string &region);
  void setRegion(const std::string &region);
  json getSummonerByName(const std::string &name);

 private:
  std::string region;
};

#endif //POO_INCLUDE_CLIENT_H_
