#include "Entities/GameEntity.hpp"
#include "GameEvents.hpp"

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

void GameEvents::addUpdateEntity(std::shared_ptr<GameEntity> entity) {
    this->updateEntitiesList.insert(std::pair<int, std::shared_ptr<GameEntity>>(entity->getId(), entity));
    entity->setEventParent(this);
}

void GameEvents::notifyUpdateEntities() {
    for (auto entity : this->updateEntitiesList) {
        entity.second->update();
    }
}

bool GameEvents::updateListContains(const GameEntity& entity) {
    return this->updateEntitiesList.find(entity.getId()) != this->updateEntitiesList.end();
}

void GameEvents::removeUpdateEntity(const GameEntity& entity) {
    if (this->updateListContains(entity)) {
        this->updateEntitiesList.erase(entity.getId());
    }
}

void GameEvents::addDrawEntity(std::shared_ptr<GameEntity> entity, int layer) {
    this->getDrawLayerMap(layer).insert(std::pair<int, std::shared_ptr<GameEntity>>(entity->getId(), entity));
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

bool GameEvents::drawListContains(const GameEntity& entity) {
    return this->drawEntitiesList.find(entity.getId()) != this->drawEntitiesList.end();
}

void GameEvents::removeDrawEntity(const GameEntity& entity) {
    if (this->drawListContains(entity)) {
        this->drawEntitiesList.at(entity.getDrawLayer()).erase(entity.getId());
    }
}

void GameEvents::notifyAll() {
    this->notifyUpdateEntities();
    this->notifyDrawEntities();
}

void GameEvents::removeFromAll(const GameEntity& entity) {
    this->removeUpdateEntity(entity);
    this->removeDrawEntity(entity);
}

GameEvents::ENTITY_MAP& GameEvents::getDrawLayerMap(const int layer) {
    auto find = this->drawEntitiesList.find(layer);
    if (find == this->drawEntitiesList.end()) {
        this->drawEntitiesList.insert(std::pair<int, ENTITY_MAP>(layer, ENTITY_MAP()));
    }

    return this->drawEntitiesList.at(layer);
}
