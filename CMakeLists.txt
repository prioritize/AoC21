cmake_minimum_required(VERSION 3.20)
project(AoC21)

add_subdirectory(include)
set(CMAKE_CXX_STANDARD 20)

add_executable(Template main.cpp)
target_link_libraries(Template fmt::fmt)
