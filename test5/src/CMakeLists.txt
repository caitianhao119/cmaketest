set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
add_library(sum sum.cpp)
add_executable(main main.cpp)
target_link_libraries(main sum)