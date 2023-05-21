#include "GameEntity.hpp"
#include "GameState/GameEvents.hpp"

GameEntity::GameEntity(GameEntity::ID_TYPE id, int layer) {
    this->id = id;
    this->setMapLayer(layer);
    this->setDrawLayer(0);
    this->eventParent = nullptr;
    this->speed = 0;
}

void GameEntity::releaseReferences() {
    if (this->eventParent) {
        eventParent->removeFromAll(*this);
    }
}
