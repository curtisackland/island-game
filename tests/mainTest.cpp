#define BOOST_TEST_MODULE MainTests
#define BOOST_TEST_DYN_LINK
// This file has the boost test main, so it takes a long time  to compile
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>


// Docs: https://www.boost.org/doc/libs/1_71_0/libs/test/doc/html/index.html

/*
Generic test suite template:
Put the class name + "Test" as the name of the suite
*/
BOOST_AUTO_TEST_SUITE(OtherClassTest)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_WARN_EQUAL(101, 101); // Tests pass when not working
    BOOST_CHECK_EQUAL(101, 101); // Tests fail when not working
    BOOST_REQUIRE_EQUAL(101, 101); // Testing stops when not working
}

BOOST_AUTO_TEST_SUITE_END()

