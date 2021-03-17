cmake_minimum_required(VERSION 3.16)
project(poo)

set(CMAKE_CXX_STANDARD 14)
add_executable(poo main.cpp)

include(FetchContent)
# cpr:
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG 41fbaca90160950f1397e0ffc6b58bd81063f131) # the commit hash for 1.5.2
FetchContent_MakeAvailable(cpr)
target_link_libraries(poo PRIVATE cpr::cpr)

# json:
FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.7.3)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
target_link_libraries(poo PRIVATE nlohmann_json::nlohmann_json)