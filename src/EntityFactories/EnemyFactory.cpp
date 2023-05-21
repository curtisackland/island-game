#include "EnemyFactory.hpp"

void EnemyFactory::createEntity(EntityManager& manager, GameEntity::ID_TYPE id, std::shared_ptr<GameEntity> target, int layer) {
    manager.setEntity(id, std::make_unique<Enemy>(id, target, layer));
}

GameEntity::ID_TYPE EnemyFactory::createEntity(EntityManager& manager, std::shared_ptr<GameEntity> target, int layer) {
    GameEntity::ID_TYPE id = manager.generateID();
    createEntity(manager, id, target, layer);
    return id;
}
