cmake_minimum_required(VERSION 3.16)
project(poo)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_USE_WINSSL ON)
#set(USE_WINSSL ON)
#set(CMAKE_USE_OPENSSL OFF)
#set(USE_OPENSSL OFF)
#set(BUILD_CPR_TESTS OFF)
add_executable(poo main.cpp)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG 41fbaca90160950f1397e0ffc6b58bd81063f131) # the commit hash for 1.5.2
FetchContent_MakeAvailable(cpr)

target_link_libraries(poo PRIVATE cpr::cpr)
