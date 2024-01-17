#include "GameEntityTest.hpp"

GameEntityTest::GameEntityTest(int id, int layer) : GameEntity(id, layer) {

}

GameEntityTest::~GameEntityTest() {

}

void GameEntityTest::update() {
    this->internalVariable = true;
}

void GameEntityTest::draw() {
    this->internalVariable2 = true;
}
