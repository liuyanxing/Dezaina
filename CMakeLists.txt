cmake_minimum_required(VERSION 3.5)

project(Desaina)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE src/main.cpp)

add_subdirectory(src/core)
add_subdirectory(src/ui)