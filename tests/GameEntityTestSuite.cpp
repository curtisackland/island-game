#include "common/boost_test.hpp"
#include "common/classes/GameEntityTest.hpp"

//#include "../src/Entities/GameEntity.hpp"

BOOST_AUTO_TEST_SUITE(GameEntityTestSuite)

BOOST_AUTO_TEST_CASE(ConstructorDestructor) {
    GameEntityTest entity(0);
}

BOOST_AUTO_TEST_SUITE_END()
