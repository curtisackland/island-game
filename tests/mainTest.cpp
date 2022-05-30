#define BOOST_TEST_MODULE MainTests
#include <boost/test/included/unit_test.hpp>
#include "GameConfig.hpp"
// Docs: https://www.boost.org/doc/libs/1_71_0/libs/test/doc/html/index.html

BOOST_AUTO_TEST_SUITE(GameConfigTest)

BOOST_AUTO_TEST_CASE(GetInstanceTest) {
    BOOST_REQUIRE_NE(&GameConfig::getInstance(), nullptr);
}

BOOST_AUTO_TEST_CASE(FileNotAdded, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJson("nofile"), std::out_of_range);
    //BOOST_CHECK_NE(1,2);
}

BOOST_AUTO_TEST_CASE(FileNotFound, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    BOOST_CHECK_THROW(GameConfig::getInstance().addFile(""), boost::wrapexcept<boost::system::system_error>);
}

BOOST_AUTO_TEST_CASE(AddFile, * boost::unit_test::depends_on("GameConfigTest/GetInstanceTest")) {
    GameConfig::getInstance().addFile("tests/testConfig.json");
}

BOOST_AUTO_TEST_CASE(AddFileTwice, * boost::unit_test::depends_on("GameConfigTest/AddFile")) {
    GameConfig::getInstance().addFile("tests/testConfig.json");
}

BOOST_AUTO_TEST_CASE(ReadConfig, * boost::unit_test::depends_on("GameConfigTest/AddFileTwice")) {
    GameConfig::getInstance().forceRead();
}

BOOST_AUTO_TEST_CASE(ReadProperty, * boost::unit_test::depends_on("GameConfigTest/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/testConfig.json")["testNumber"], (boost::json::number)1);
    //GameConfig::getInstance().getProperty();
}

BOOST_AUTO_TEST_CASE(ChangeProperty, * boost::unit_test::depends_on("GameConfigTest/AddFile")) {

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
