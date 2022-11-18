cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(test LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(GOOGLETEST_VERSION 1.12.1)

include_directories(${CMAKE_SOURCE_DIR}/nlohmann)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR})

# message(${CMAKE_SOURCE_DIR})
configure_file(config.h.in ../config.h @ONLY)

set(SOURCE_FILES_MAIN
    main.cpp
    src/jsonfile.cpp
)

add_executable(target ${SOURCE_FILES_MAIN})
# target_include_directories(target PUBLIC ${CMAKE_SOURCE_DIR}/nlohmann)
# target_include_directories(target PUBLIC ${CMAKE_SOURCE_DIR}/src)
# target_include_directories(target PUBLIC ${CMAKE_SOURCE_DIR})