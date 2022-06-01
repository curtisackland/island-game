#include "GameEvents.hpp"

GameEvents::GameEvents() {

}

GameEvents::~GameEvents() {

}

void GameEvents::addUpdateEntity(GameEntity *entity) {
    this->updateEntitiesList.insert(std::pair<int, GameEntity*>(entity->getId(), entity));
}

void GameEvents::notifyUpdateEntities() {
    for (auto entity : this->updateEntitiesList) {
        entity.second->update();
    }
}

bool GameEvents::contains(GameEntity *entity) {
    return this->updateEntitiesList.find(entity->getId()) != this->updateEntitiesList.end();
}

void GameEvents::removeEntity(GameEntity *entity) {
    this->updateEntitiesList.erase(entity->getId());
}

void GameEvents::notifyAll() {
    this->notifyUpdateEntities();
}