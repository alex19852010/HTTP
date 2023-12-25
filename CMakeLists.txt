cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)
add_executable(untitled main.cpp)

target_link_libraries(untitled PRIVATE nlohmann_json::nlohmann_json)