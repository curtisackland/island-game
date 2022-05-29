#define BOOST_TEST_MODULE MainTests
#include <boost/test/included/unit_test.hpp>
#include "../src/GameConfig.hpp"
// Docs: https://www.boost.org/doc/libs/1_71_0/libs/test/doc/html/index.html

BOOST_AUTO_TEST_SUITE(GameConfigTest)

BOOST_AUTO_TEST_CASE(GetInstanceTest) {
    BOOST_REQUIRE_NE(&GameConfig::getInstance(), nullptr);
}

BOOST_AUTO_TEST_CASE(FileNotAdded, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJsonObject("nofile"), boost::json::string);
    //BOOST_CHECK_NE(1,2);
}

BOOST_AUTO_TEST_CASE(FileNotFound, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    GameConfig::getInstance().addFile("");
}

BOOST_AUTO_TEST_CASE(ReadConfig, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    GameConfig::getInstance().addFile
}

BOOST_AUTO_TEST_CASE(ReadConfig, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    GameConfig::getInstance().addFile
}

BOOST_AUTO_TEST_CASE(ReadConfig, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    GameConfig::getInstance().addFile
}


BOOST_AUTO_TEST_SUITE_END()

/*
Generic test suite template:
Put the class name + "Test" as the name of the suite
BOOST_AUTO_TEST_SUITE(OtherClassTest)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_WARN_EQUAL(101, 101); // Tests pass when not working
    BOOST_CHECK_EQUAL(101, 101); // Tests fail when not working
    BOOST_REQUIRE_EQUAL(101, 101); // Testing stops when not working
}

BOOST_AUTO_TEST_SUITE_END()
*/
