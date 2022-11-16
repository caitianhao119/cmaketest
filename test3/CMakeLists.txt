cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)

# system name
message(${CMAKE_SYSTEM_NAME})
# compiler version
message(${CMAKE_CXX_COMPILER_ID})
# compiler bytes
message(${CMAKE_SIZEOF_VOID_P})

# foreach(key
#   IN ITEMS
#     CMAKE_SYSTEM_NAME
#     CMAKE_CXX_COMPILER_ID
#   )
#   cmake_host_system_information(RESULT _${key} QUERY ${key})
# endforeach()

configure_file(config.h.in ../config.h @ONLY)
add_executable(message message.cpp config.h)