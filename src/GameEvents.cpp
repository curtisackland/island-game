#include "GameEntity.hpp"
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

bool GameEvents::updateListContains(GameEntity *entity) {
    return this->updateEntitiesList.find(entity->getId()) != this->updateEntitiesList.end();
}

void GameEvents::removeUpdateEntity(GameEntity *entity) {
    this->updateEntitiesList.erase(entity->getId());
}

void GameEvents::addDrawEntity(GameEntity *entity, int layer) {
    this->drawEntitiesList.insert(std::pair<int, UPDATE_ENTITIES_LIST_TYPE>(layer, UPDATE_ENTITIES_LIST_TYPE()));
    this->drawEntitiesList.at(layer).insert(std::pair<int, GameEntity*>(entity->getId(), entity));
    entity->setDrawLayer(layer);
}

void GameEvents::notifyDrawEntities() {
    for (auto drawEntitiesListLayer : this->drawEntitiesList) {
        for (auto entity : drawEntitiesListLayer.second) {
            entity.second->draw();
        }
    }
}

bool GameEvents::drawListContains(GameEntity *entity) {
    return this->drawEntitiesList.find(entity->getId()) != this->drawEntitiesList.end();
}

void GameEvents::removeDrawEntity(GameEntity *entity) {
    this->drawEntitiesList.at(entity->getDrawLayer()).erase(entity->getId());
}

void GameEvents::notifyAll() {
    this->notifyUpdateEntities();
    this->notifyDrawEntities();
}

void GameEvents::removeFromAll(GameEntity *entity) {
    this->removeUpdateEntity(entity);
    this->removeDrawEntity(entity);
}