#include <iostream>
#include <string>
#include "Summoner.h"

int main() {
  if (!std::getenv("RIOTAPI"))
    std::cout << "Missing RIOT API Key. \n Set up a new 'RIOTAPI' environment variable!";

  Summoner s = Summoner("BESTSKYBREAKER");

  std::cout << s;
  return 0;
}