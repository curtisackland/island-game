#include "common/boost_test.hpp"

#include "../src/GameConfig.hpp"

BOOST_AUTO_TEST_SUITE(GameConfigTestSuite)

BOOST_AUTO_TEST_CASE(GetInstanceTest) {
    BOOST_REQUIRE_NE(&GameConfig::getInstance(), nullptr);
}

BOOST_AUTO_TEST_CASE(FileNotAdded) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJson("nofile"), std::ifstream::failure);
}

BOOST_AUTO_TEST_CASE(BadJsonForm) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJson("tests/common/resources/testConfigBad.json"), boost::wrapexcept<boost::system::system_error>);
}

BOOST_AUTO_TEST_CASE(BadJsonForm2) {
    BOOST_CHECK_THROW(GameConfig::getInstance().getJson("tests/common/resources/testConfigBad2.json"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(FileNotFound) {
    BOOST_CHECK_THROW(GameConfig::getInstance().addFile("tests/common/resources/notFound.json"), std::ifstream::failure);
}

BOOST_AUTO_TEST_CASE(AddFile) {
    BOOST_REQUIRE_NO_THROW(GameConfig::getInstance().addFile("tests/common/resources/testConfig.json"));
}

BOOST_AUTO_TEST_CASE(AddFileTwice, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_REQUIRE_NO_THROW(GameConfig::getInstance().addFile("tests/common/resources/testConfig.json"));
}

BOOST_AUTO_TEST_CASE(ReadConfig, * boost::unit_test::depends_on("GameConfigTestSuite/AddFileTwice")) {
    BOOST_REQUIRE_NO_THROW(GameConfig::getInstance().forceRead());
}

BOOST_AUTO_TEST_CASE(ReadPropertyInteger, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig.json").at("testInteger"), 1);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig.json").at("testInteger").as_int64(), 1);
}

BOOST_AUTO_TEST_CASE(ReadPropertyDouble, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig.json").at("testDouble"), 1.5);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig.json").at("testDouble").as_double(), 1.5);
}

BOOST_AUTO_TEST_CASE(ReadPropertyString, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig.json").at("testString"), "Hello");
}

BOOST_AUTO_TEST_CASE(ReadPropertyObject, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig.json").at("testObject").at("objectInteger"), 1);
}

BOOST_AUTO_TEST_CASE(AddFile2) {
    GameConfig::getInstance().addFile("tests/common/resources/testConfig2.json");
}

BOOST_AUTO_TEST_CASE(ReadPropertyInteger2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig2.json").at("testInteger2"), 1);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig2.json").at("testInteger2").as_int64(), 1);
}

BOOST_AUTO_TEST_CASE(ReadPropertyDouble2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig2.json").at("testDouble2"), 1.5);
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig2.json").at("testDouble2").as_double(), 1.5);
}

BOOST_AUTO_TEST_CASE(ReadPropertyString2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig2.json").at("testString2"), "Hello");
}

BOOST_AUTO_TEST_CASE(ReadPropertyObject2, * boost::unit_test::depends_on("GameConfigTestSuite/AddFile2")) {
    BOOST_CHECK_EQUAL(GameConfig::getInstance().getJson("tests/common/resources/testConfig2.json").at("testObject2").at("objectInteger2"), 1);
}

BOOST_AUTO_TEST_SUITE_END()
