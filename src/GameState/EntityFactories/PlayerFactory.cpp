#include "PlayerFactory.hpp"

void PlayerFactory::createEntity(GameEntity::ID_TYPE id, int layer) {
    manager->setEntity(id, new Player(id, layer));
}

GameEntity::ID_TYPE PlayerFactory::createEntity(int layer) {
    GameEntity::ID_TYPE id = manager->generateID();
    manager->setEntity(id, new Player(id, layer));
    return id;
}
