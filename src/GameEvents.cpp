#include "GameEntity.hpp"
#include "GameEvents.hpp"

GameEvents::GameEvents() {

}

GameEvents::~GameEvents() {
    // Remove entity references to this object
    for (auto entity : this->updateEntitiesList) {
        entity.second->setEventParent(nullptr);
    }
    for (auto layer : this->drawEntitiesList) {
        for (auto entity : layer.second) {
            entity.second->setEventParent(nullptr);
        }
    }
}

void GameEvents::addUpdateEntity(GameEntity *entity) {
    this->updateEntitiesList.insert(std::pair<int, GameEntity*>(entity->getId(), entity));
    entity->setEventParent(this);
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
    if (this->updateListContains(entity)) {
        this->updateEntitiesList.erase(entity->getId());
    }
}

void GameEvents::addDrawEntity(GameEntity *entity, int layer) {
    if (this->drawEntitiesList.find(layer) == this->drawEntitiesList.end())
        this->drawEntitiesList.insert(std::pair<int, UPDATE_ENTITIES_LIST_TYPE>(layer, UPDATE_ENTITIES_LIST_TYPE()));
    this->drawEntitiesList.at(layer).insert(std::pair<int, GameEntity*>(entity->getId(), entity));
    entity->setDrawLayer(layer);
    entity->setEventParent(this);
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
    if (this->drawListContains(entity)) {
        this->drawEntitiesList.at(entity->getDrawLayer()).erase(entity->getId());
    }
}

void GameEvents::notifyAll() {
    this->notifyUpdateEntities();
    this->notifyDrawEntities();
}

void GameEvents::removeFromAll(GameEntity *entity) {
    this->removeUpdateEntity(entity);
    this->removeDrawEntity(entity);
}