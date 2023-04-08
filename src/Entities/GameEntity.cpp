#include "GameEntity.hpp"
#include "../GameEvents.hpp"

unsigned long long GameEntity::top_id = 0;

GameEntity::GameEntity(const std::shared_ptr<GameState>& state, int layer) {
    this->gameStatePtr = state;
    this->id = top_id++;
    this->setMapLayer(layer);
    this->setDrawLayer(0);
    this->eventParent = nullptr;
    this->speed = 0;
}

GameEntity::~GameEntity() {
    if (this->eventParent) {
        eventParent->removeFromAll(*this);
    }
}
