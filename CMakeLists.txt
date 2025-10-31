cmake_minimum_required(VERSION 3.15)
project(boosttest_demo)

set(CMAKE_CXX_VERSION 17)
set(CMAKE_CXX_VERSION_REQUIRED OFF)
set(CMAKE_CXX_COMPILER_EXTENTION OFF)

enable_testing()
include(CTest)

add_subdirectory(src)
add_subdirectory(test)
