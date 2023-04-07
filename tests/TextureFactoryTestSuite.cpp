#include "common/boost_test.hpp"

#include "../src/TextureFactory.hpp"

BOOST_AUTO_TEST_SUITE(TextureFactoryTestSuite, * boost::unit_test::enable_if<!SKIP_SFML_TESTS>())

BOOST_AUTO_TEST_CASE(LoadTexture) {
    TextureFactory::getTexture("tests/grass.png");
}

BOOST_AUTO_TEST_CASE(LoadTextureTwice, * boost::unit_test::depends_on("TextureFactoryTestSuite/LoadTexture")) {
    TextureFactory::getTexture("tests/grass.png");
}

BOOST_AUTO_TEST_CASE(LoadSecondTexture, * boost::unit_test::depends_on("TextureFactoryTestSuite/LoadTexture")) {
    TextureFactory::getTexture("tests/master.png");
}

BOOST_AUTO_TEST_SUITE_END()
