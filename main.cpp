#include <iostream>
#include <cpr/cpr.h>

int main() {
//    if(const char* env_p = std::getenv("RIOTAPI"))
//        std::cout << "Your RIOT API Key is: " << env_p << '\n';
//    else
//        std::cout << "Missing RIOT API Key. \n Set up a new 'RIOTAPI' environment variable!";
    cpr::Response r = cpr::Get(cpr::Url{"http://www.httpbin.org/get"});
    std::cout << r.status_code << std::endl; // http://www.httpbin.org/get
    return 0;
}