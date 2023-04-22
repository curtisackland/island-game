#include "EntityManager.hpp"

GameEntity * const EntityManager::getEntity(GameEntity::ID_TYPE id) {
    auto entity = entities.find(id);
    if (entity == entities.end()) {
        return nullptr;
    } else {
        return entity->second.get();
    }
}

void EntityManager::setEntity(GameEntity* entity) {
    GameEntity::ID_TYPE id = this->generateID();
    setEntity(id, entity);
}

GameEntity::ID_TYPE EntityManager::setEntity(GameEntity::ID_TYPE id, GameEntity* entity) {
    entities.try_emplace(id, std::make_unique<GameEntity>(entity));
}
