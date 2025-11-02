add_executable(test_math_utils test_math_utils.cpp)

target_link_libraries(test_math_utils PUBLIC math_utils)
target_include_directories(test_math_utils PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(test_math_utils PRIVATE -O2)
target_compile_definitions(test_math_utils PRIVATE TEST_MACRO)

# This tells CMake to search your system for Boost libraries and specifically the unit
# test framework component.
# looks for boost installations in standard system paths like /usr/include, /usr/lib
# REQUIRED means if Boost or the requested component (unit_test_framework) is not found,
# CMake will stop with an error.
# COMPONENTS unit_test_framework specifies which part of Boost you need.
# If successful, the command defines useful variables.
# Boost_FOUND -> TRUE if found.
# Boost_INCLUDE_DIRS -> path to Boost header e.g /usr/include
# Boost_LIBRARIES -> paths to Boost libraries to link against
# Boost_UNIT_TEST_FRAMEWORK_LIBRARY -> full path to libboost_unit_test_framework.so or .a
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Adds include directories globally. Affects all future targets, 
# hard to maintain in large projects.
#include_directories(${BOOST_INCLUDE_DIRS} include)

# target specifc includ: scoped and explicit.
target_include_directories(test_math_utils PRIVATE ${Boost_INCLUDE_DIRS})
message(STATUS "BOOST_UNIT_TEST_FRAMEWORK_LIBRARY: ${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY}")

# Not required, as we are using the included header option.
#target_link_libraries(test_math_utils 
#	              PUBLIC
#		      ${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY}
#	      )

enable_testing()
include(CTest)

add_test(NAME my_boost_test_run COMMAND test_math_utils)
