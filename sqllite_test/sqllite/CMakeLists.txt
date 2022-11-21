PROJECT(sqlite3)
cmake_minimum_required(VERSION 2.8)

# include_directories(${CMAKE_SOURCE_DIR}/src)
# add_library(sqlite3 STATIC src/sqlite3.c src/sqlite3.h src/sqlite3ext.h)
# add_executable(sqlite src/sqlite3.c src/shell.c src/sqlite3.h src/sqlite3ext.h)

#add_executable(main main.cpp)
#target_link_libraries(main sqlite3)


# install(FILES src/sqlite3.h src/sqlite3ext.h DESTINATION include)
# install(TARGETS sqlite3 LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

configure_file(config.h.in ../config.h @ONLY)

set(SOURCE_FILES_MAIN
    test.cpp
    src/sqlite3.c
    src/sqlite3.h
)
add_executable(target ${SOURCE_FILES_MAIN})