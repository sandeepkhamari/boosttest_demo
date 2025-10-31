add_executable(test_math_utils test_math_utils.cpp)

target_link_libraries(test_math_utils PUBLIC math_utils)
target_include_directories(test_math_utils PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(test_math_utils PRIVATE -O2)
target_compile_definitions(test_math_utils PRIVATE TEST_MACRO)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${BOOST_INCLUDE_DIRS} include)

message(STATUS "BOOST_UNIT_TEST_FRAMEWORK_LIBRARY: ${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY}")

target_link_libraries(test_math_utils 
	              PUBLIC
		      ${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY}
	      )

enable_testing()
include(CTest)

add_test(NAME my_boost_test_run COMMAND test_math_utils)
