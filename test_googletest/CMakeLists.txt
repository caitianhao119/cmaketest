cmake_minimum_required(VERSION 3.5)

project(bobbytest LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(GOOGLETEST_VERSION 1.12.1)

# message(${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
# message(${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
# set path
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/bin)
set(EXECUTABLE_OUTPUT_PATH 
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/bin)
enable_testing()

include(CMakeDependentOption)
include(GNUInstallDirs)

add_subdirectory(googletest)
add_subdirectory(src)

add_executable(target test.cpp)
target_include_directories(target PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(target PUBLIC ${CMAKE_SOURCE_DIR}/googletest)

target_link_libraries(target sum)
target_link_libraries(target gtest)
