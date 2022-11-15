add_library(message
  STATIC
    Message.hpp
    Message.cpp
  )
  add_executable(target test2.cpp)
  target_link_libraries(target message)