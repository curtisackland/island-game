#include "GameEntityTest.hpp"

GameEntityTest::GameEntityTest(std::shared_ptr<GameState> gameStatePtr, int layer) : GameEntity(gameStatePtr, layer) {

}

GameEntityTest::~GameEntityTest() {

}

void GameEntityTest::update() {
    this->internalVariable = true;
}

void GameEntityTest::draw() {
    this->internalVariable2 = true;
}
