cmake_minimum_required(VERSION 3.15)
project(boosttest_demo)

set(CMAKE_CXX_VERSION 17)
set(CMAKE_CXX_VERSION_REQUIRED OFF)
set(CMAKE_CXX_COMPILER_EXTENTION OFF)

# /usr/share/cmake-3.28/Modules/FindBoost.cmake
# /usr/lib/x86_64-linux-gnu/cmake/Boost-1.83.0/BoostConfig.cmake

# As both libboost_unit_test_framework.a and libboost_unit_test_framework.so are provided.
# we need to provide/select which one we should use.
# THIS IS NOT USED ANYWHERE.
find_library(BOOST NAME libboost_unit_test_framework.a  HINTS /usr/lib/x86_64-linux-gnu)
if(BOOST)
   message(STATUS "BOOST: ${BOOST}")
else()
   message(STATUS "BOOST NOT FOUND")
endif()

find_path(BOOST_INCLUDE_DIR
	  NAME chrono.hpp
	  HINTS /usr/include/boost
	  PATH
	     /usr/local/include
	     /usr/include/boost/chrono.hpp
	  DOC "boost include directories"
  )

message(STATUS "BOOST_INCLUDE_DIR: ${BOOST_INCLUDE_DIR}")

enable_testing()
include(CTest)

add_subdirectory(src)
add_subdirectory(test)
