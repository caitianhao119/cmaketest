cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(GOOGLETEST_VERSION 1.12.1)

include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/include)
include_directories(PUBLIC ${CMAKE_SOURCE_DIR}/src)

configure_file(config.h.in ../config.h @ONLY)

set(SOURCE_FILES_MAIN
    test.cpp
    src/baselogger.cpp
    src/logsystem.cpp
)

add_executable(target ${SOURCE_FILES_MAIN})