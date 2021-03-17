#include "Summoner.h"
#include <string>
#include <iostream>
#include "Client.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::ostream &operator<<(std::ostream &os, const Summoner &summoner) {
  os << "accountId: " << summoner.accountId << "\nprofileIconId: " << summoner.profileIconId << "\nrevisionDate: "
     << summoner.revisionDate << "\nname: " << summoner.name << "\nid: " << summoner.id << "\npuuid: " << summoner.puuid
     << "\nsummonerLevel: " << summoner.summonerLevel;
  return os;
}
Summoner::Summoner(const std::string &name) : name(name) {
  this->setByName(name);
}

Summoner::Summoner() {
  this->profileIconId = 0;
  this->revisionDate = 0;
  this->summonerLevel = 0;
}

void Summoner::setByName(const std::string &name) {
  Client c = Client("eun1");
  json j = c.getSummonerByName("BESTSKYBREAKER");
  this->accountId = j["accountId"].get<std::string>();
  this->profileIconId = j["profileIconId"].get<int>();
  this->revisionDate = j["revisionDate"].get<long>();
  this->name = j["name"].get<std::string>();
  this->id = j["id"].get<std::string>();
  this->puuid = j["puuid"].get<std::string>();
  this->summonerLevel = j["summonerLevel"].get<long>();
}