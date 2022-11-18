cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(GOOGLETEST_VERSION 1.12.1)

include_directories(${CMAKE_SOURCE_DIR}/nlohmann)
# message(${CMAKE_SOURCE_DIR})
configure_file(config.h.in ../config.h @ONLY)

add_executable(target main.cpp)
target_include_directories(target PUBLIC ${CMAKE_SOURCE_DIR}/nlohmann)
target_include_directories(target PUBLIC ${CMAKE_SOURCE_DIR})