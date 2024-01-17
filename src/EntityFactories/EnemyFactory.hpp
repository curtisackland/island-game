#pragma once
#include <memory>
#include "FactoryBaseClass.hpp"
#include "Entities/Enemy.hpp"
#include "GameState/EntityManager.hpp"

class EnemyFactory : FactoryBaseClass {
public:
    EnemyFactory() = default;
    ~EnemyFactory() = default;
    static void createEntity(EntityManager& manager, GameEntity::ID_TYPE id, std::shared_ptr<GameEntity> target, int layer);
    static GameEntity::ID_TYPE createEntity(EntityManager& manager, std::shared_ptr<GameEntity> target, int layer);
};
