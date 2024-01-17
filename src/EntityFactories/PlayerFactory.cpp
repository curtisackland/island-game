#include "PlayerFactory.hpp"

void PlayerFactory::createEntity(EntityManager& manager, GameEntity::ID_TYPE id, int layer) {
    manager.setEntity(id, std::make_unique<Player>(id, layer));
}

GameEntity::ID_TYPE PlayerFactory::createEntity(EntityManager& manager, int layer) {
    GameEntity::ID_TYPE id = manager.generateID();
    createEntity(manager, id, layer);
    return id;
}
