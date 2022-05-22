#include "mainTest.hpp"
#define BOOST_TEST_MODULE MyTest TestSuites
#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(suite1)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()