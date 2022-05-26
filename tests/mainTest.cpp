#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>
// Docs: https://www.boost.org/doc/libs/1_75_0/libs/test/doc/html/index.html

BOOST_AUTO_TEST_SUITE(GameConfig)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_CHECK_EQUAL(101, 101);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(OtherClass)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_WARN_EQUAL(101, 101);
    BOOST_CHECK_EQUAL(101, 101);
    BOOST_REQUIRE_EQUAL(101, 101);
}

BOOST_AUTO_TEST_SUITE_END()