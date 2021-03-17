#include "Client.h"
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>
using json = nlohmann::json;

Client::Client(const std::string &region) : region(region) {
  this->region = region;
}

void Client::setRegion(const std::string &region)  {
    this->region = region;
}

json Client::getSummonerByName(const std::string &name) {
  cpr::Response r;
  r = cpr::Get(
      cpr::Url{"https://" + this->region + ".api.riotgames.com/lol/summoner/v4/summoners/by-name/" + name},
      cpr::VerifySsl{false},
      cpr::Header{{"X-Riot-Token", std::getenv("RIOTAPI")}}
  );
  if (r.status_code != 200) {
    std::cerr << "Got status code " << r.status_code << "\n";
  } else {
    json j = json::parse(r.text);
    return j;
  }
}