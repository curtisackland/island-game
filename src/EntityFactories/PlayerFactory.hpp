#pragma once
#include "FactoryBaseClass.hpp"
#include "GameState/EntityManager.hpp"
#include "Entities/Player.hpp"

class PlayerFactory : FactoryBaseClass {
public:
    static void createEntity(EntityManager& manager, GameEntity::ID_TYPE id, int layer);
    static GameEntity::ID_TYPE createEntity(EntityManager& manager, int layer);
};
