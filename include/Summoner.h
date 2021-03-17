#include <string>
#include <iostream>
#ifndef POO_INCLUDE_SUMMONER_H_
#define POO_INCLUDE_SUMMONER_H_

class Summoner {
 public:
  Summoner(const std::string &name);
  Summoner();

  friend std::ostream &operator<<(std::ostream &os, const Summoner &summoner);

  void setByName(const std::string &name);

 private:
  std::string accountId;
  int profileIconId;
  long revisionDate;
  std::string name;
  std::string id;
  std::string puuid;
  long summonerLevel;
  std::string region;
};

#endif //POO_INCLUDE_SUMMONER_H_
