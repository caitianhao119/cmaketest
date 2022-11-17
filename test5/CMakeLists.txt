cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

macro(add_catch_test _name _cost)
  math(EXPR num_macro_calls "${num_macro_calls} + 1")
  message(STATUS "add_catch_test called with ${ARGC} arguments: ${ARGV}")
  set(_argn "${ARGN}")
  if(_argn)
      message(STATUS "oops - macro received argument(s) we did not expect: ${ARGN}")
  endif()
  add_test(
    NAME
      ${_name}
    COMMAND
      $<TARGET_FILE:cpp_test>
    [${_name}] --success --out
    ${PROJECT_BINARY_DIR}/tests/${_name}.log --durations yes
    WORKING_DIRECTORY
      ${CMAKE_CURRENT_BINARY_DIR}
    )
  set_tests_properties(
    ${_name}
    PROPERTIES
        COST ${_cost}
    )
endmacro()

set(num_macro_calls 0)
add_catch_test(short 1.5)
add_catch_test(long 2.5 extra_argument)
message(STATUS "in total there were ${num_macro_calls} calls to add_catch_test")