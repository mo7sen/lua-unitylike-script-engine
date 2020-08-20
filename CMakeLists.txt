cmake_minimum_required(VERSION 3.1)

project(unitylike_lua)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(unitylike_lua
  src/main.c
  src/object.c
  src/object_l.c
  )

target_include_directories(unitylike_lua PUBLIC
  include
  )

target_link_libraries(unitylike_lua
  lua5.3
  )

file(COPY scripts DESTINATION ${unitylike_lua_BINARY_DIR})

