#include "PlayerFactory.hpp"

PlayerFactory::PlayerFactory(std::shared_ptr<EntityManager> manager) : FactoryBaseClass(manager) {
}

inline void PlayerFactory::createEntity(GameEntity::ID_TYPE id, int layer) {
    manager->setEntity(id, std::make_unique<Player>(id, layer));
}

inline GameEntity::ID_TYPE PlayerFactory::createEntity(int layer) {
    GameEntity::ID_TYPE id = manager->generateID();
    createEntity(id, layer);
    return id;
}
