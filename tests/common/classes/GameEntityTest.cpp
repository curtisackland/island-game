#include "GameEntityTest.hpp"

GameEntityTest::GameEntityTest(int layer) : GameEntity(layer) {

}

GameEntityTest::~GameEntityTest() {

}

void GameEntityTest::update() {
    this->internalVariable = true;
}

void GameEntityTest::draw() {
    this->internalVariable2 = true;
}