#include "common/boost_test.hpp"
#include "common/classes/GameEntityTest.hpp"

#include "../src/GameEvents.hpp"

BOOST_AUTO_TEST_SUITE(GameEventsTestSuite)

BOOST_AUTO_TEST_CASE(CreateGameEventsWithEntity) {
    auto events = std::make_shared<GameEvents>();
    auto entity = std::make_shared<GameEntityTest>(nullptr, 0);
    events->addUpdateEntity(entity);
    BOOST_CHECK(events->updateListContains(*entity.get()));
    events->removeUpdateEntity(*entity.get());
}

BOOST_AUTO_TEST_CASE(CheckNoNotify) {
    auto events = std::make_shared<GameEvents>();
    auto entity = std::make_shared<GameEntityTest>(nullptr, 0);
    events->addUpdateEntity(entity);
    BOOST_CHECK(!entity->getInternalVariable());
    events->removeUpdateEntity(*entity.get());
}

BOOST_AUTO_TEST_CASE(CheckNotify) {
    auto events = std::make_shared<GameEvents>();
    auto entity = std::make_shared<GameEntityTest>(nullptr, 0);
    events->addUpdateEntity(entity);
    events->notifyAll();
    BOOST_CHECK(entity->getInternalVariable());
    events->removeUpdateEntity(*entity.get());
}

BOOST_AUTO_TEST_CASE(CheckNoDrawNotify) {
    auto events = std::make_shared<GameEvents>();
    auto entity = std::make_shared<GameEntityTest>(nullptr, 0);
    events->addUpdateEntity(entity);
    BOOST_CHECK(!entity->getInternalVariable2());
    events->removeUpdateEntity(*entity.get());
}

BOOST_AUTO_TEST_CASE(CheckDrawNotify) {
    auto events = std::make_shared<GameEvents>();
    auto entity = std::make_shared<GameEntityTest>(nullptr, 0);
    events->addDrawEntity(entity, 0);
    events->notifyAll();
    BOOST_CHECK(entity->getInternalVariable2());
    events->removeDrawEntity(*entity.get());
}

BOOST_AUTO_TEST_CASE(CheckDestroyEntity) {
    auto events = std::make_shared<GameEvents>();
    auto entity = std::make_shared<GameEntityTest>(nullptr, 0);
    events->addUpdateEntity(entity);
    BOOST_CHECK(events->updateListContains(*entity.get()));

    events->notifyUpdateEntities();
    BOOST_CHECK(entity->getInternalVariable());

    events->removeUpdateEntity(*entity.get());
    BOOST_CHECK(!events->updateListContains(*entity.get()));
}

BOOST_AUTO_TEST_CASE(CheckDestroyEntities) {
    auto events = std::make_shared<GameEvents>();
    std::vector<std::shared_ptr<GameEntityTest>>* entityVector = new std::vector<std::shared_ptr<GameEntityTest>>();
    int const testSize = 1000;

    for (int i = 0; i < testSize; ++i) {
        entityVector->push_back(std::make_shared<GameEntityTest>(nullptr, 0));
        events->addUpdateEntity(entityVector->back());
    }

    events->notifyUpdateEntities();
    for (int i = 0; i < testSize; ++i) {
        BOOST_CHECK(entityVector->at(i)->getInternalVariable());
    }

    auto e = entityVector->at(0);
    for (int i = 0; i < testSize; ++i) {
        entityVector->at(i).reset();
    }
    delete entityVector;
    e->getId();
    BOOST_CHECK_NO_THROW(events->notifyUpdateEntities());
}


BOOST_AUTO_TEST_SUITE_END()
