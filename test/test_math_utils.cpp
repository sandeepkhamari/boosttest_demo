#include <iostream>
#define BOOST_TEST_MODULE MathUtilsTest
#include "../include/math_utils.hpp"
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(addition_test)
{
   BOOST_CHECK_EQUAL(add(2,3), 5);
   BOOST_CHECK_EQUAL(add(-1,1), 0);
}

BOOST_AUTO_TEST_CASE(multiply_test)
{
   BOOST_CHECK_EQUAL(multiply(2,3), 6);
   BOOST_CHECK_EQUAL(multiply(-1,1), -1);
}
