#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Summoner {
 public:
  Summoner(const std::string &name) : name(name) {
    this->SetByName(name);
  }

  friend std::ostream &operator<<(std::ostream &os, const Summoner &summoner) {
    os << "accountId: " << summoner.accountId << "\nprofileIconId: " << summoner.profileIconId << "\nrevisionDate: "
       << summoner.revisionDate << "\nname: " << summoner.name << "\nid: " << summoner.id << "\npuuid: " << summoner.puuid
       << "\nsummonerLevel: " << summoner.summonerLevel;
    return os;
  }

 private:
  void SetByName(const std::string &name) {
    cpr::Response r;
    r = cpr::Get(
        cpr::Url{"https://eun1.api.riotgames.com/lol/summoner/v4/summoners/by-name/" + name},
        cpr::VerifySsl{false},
        cpr::Header{{"X-Riot-Token", std::getenv("RIOTAPI")}}
    );
    if (r.status_code != 200) {
      std::cerr << "Got status code " << r.status_code << "\n";
    } else {
      json j = json::parse(r.text);
      this->accountId = j["accountId"].get<std::string>();
      this->profileIconId = j["profileIconId"].get<int>();
      this->revisionDate = j["revisionDate"].get<long>();
      this->name = j["name"].get<std::string>();
      this->id = j["id"].get<std::string>();
      this->puuid = j["puuid"].get<std::string>();
      this->summonerLevel = j["summonerLevel"].get<long>();
    }
  }

  std::string accountId;
  int profileIconId;
  long revisionDate;
  std::string name;
  std::string id;
  std::string puuid;
  long summonerLevel;
};

int main() {
  if (!std::getenv("RIOTAPI"))
    std::cout << "Missing RIOT API Key. \n Set up a new 'RIOTAPI' environment variable!";

  Summoner BESTSKYBREAKER = Summoner("BESTSKYBREAKER");

  std::cout << BESTSKYBREAKER;
  return 0;
}