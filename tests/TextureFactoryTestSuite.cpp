#include "common/boost_test.hpp"

#include "../src/GameState/TextureFactory.hpp"

BOOST_AUTO_TEST_SUITE(TextureFactoryTestSuite, * boost::unit_test::enable_if<!SKIP_SFML_TESTS>())

BOOST_AUTO_TEST_CASE(LoadTexture) {
    TextureFactory tf;
    tf.setThrowOnMissingImage(true);
    tf.getTexture("tests/common/resources/grass.png");
}

BOOST_AUTO_TEST_CASE(LoadTextureTwice) {
    TextureFactory tf;
    tf.setThrowOnMissingImage(true);
    auto a = tf.getTexture("tests/common/resources/grass.png");
    auto b = tf.getTexture("tests/common/resources/grass.png");
    BOOST_CHECK_EQUAL(a, b);
}

BOOST_AUTO_TEST_CASE(LoadSecondTexture) {
    TextureFactory tf;
    tf.setThrowOnMissingImage(true);
    auto a = tf.getTexture("tests/common/resources/grass.png");
    auto b = tf.getTexture("tests/common/resources/master.png");
    BOOST_CHECK_NE(a, b);
}

BOOST_AUTO_TEST_CASE(MissingImage) {
    TextureFactory tf;
    BOOST_CHECK_NO_THROW(tf.getTexture("nofile"));
}

BOOST_AUTO_TEST_CASE(MissingImageThrow) {
    TextureFactory tf;
    tf.setThrowOnMissingImage(true);
    BOOST_CHECK_THROW(tf.getTexture("nofile"), std::ifstream::failure);
}

BOOST_AUTO_TEST_SUITE_END()
