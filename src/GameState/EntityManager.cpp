#include "EntityManager.hpp"

GameEntity::ID_TYPE EntityManager::topID = 0;

GameEntity::ID_TYPE EntityManager::generateID() {
    return topID++;
}

std::shared_ptr<GameEntity>& EntityManager::getEntity(GameEntity::ID_TYPE id) {
    auto entity = entities.find(id);
    if (entity != entities.end()) {
        return entity->second;
    } else {
        std::string errString = "Entity with ID ";
        errString += std::to_string(id);
        errString += " does not exist";
        throw std::runtime_error(errString);
    }
}

bool EntityManager::setEntity(GameEntity::ID_TYPE * const id, std::shared_ptr<GameEntity> entity) {
    *id = this->generateID();
    return setEntity(*id, std::move(entity));
}

bool EntityManager::setEntity(GameEntity::ID_TYPE id, std::shared_ptr<GameEntity> entity) {
    return entities.try_emplace(id, std::move(entity)).second; // TODO: error handling
}
