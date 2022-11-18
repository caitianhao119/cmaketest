set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
add_library(sum sum_integers.cpp)
add_executable(src_main main.cpp)
target_link_libraries(src_main sum)