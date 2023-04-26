#include "EntityManager.hpp"

GameEntity::ID_TYPE EntityManager::topID = 0;

GameEntity::ID_TYPE EntityManager::generateID() {
    return topID++;
}

inline GameEntity * const EntityManager::getEntity(GameEntity::ID_TYPE id) {
    auto entity = entities.find(id);
    if (entity == entities.end()) {
        return nullptr;
    } else {
        return entity->second.get();
    }
}

inline GameEntity::ID_TYPE EntityManager::setEntity(std::unique_ptr<GameEntity> entity) {
    GameEntity::ID_TYPE id = this->generateID();
    setEntity(id, std::move(entity));
    return id;
}

inline void EntityManager::setEntity(GameEntity::ID_TYPE id, std::unique_ptr<GameEntity> entity) {
    entities.try_emplace(id, std::move(entity));
}
