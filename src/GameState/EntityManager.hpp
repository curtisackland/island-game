#pragma once
#include <memory>
#include <unordered_map>
#include "EntityFactories/Entities/GameEntity.hpp"

class EntityManager {
private:
    static GameEntity::ID_TYPE topID;
    std::unordered_map<GameEntity::ID_TYPE, std::shared_ptr<GameEntity>> entities;

public:
    EntityManager() = default;
    ~EntityManager() = default;

    GameEntity::ID_TYPE generateID();
    std::shared_ptr<GameEntity>& getEntity(GameEntity::ID_TYPE id);
    bool setEntity(GameEntity::ID_TYPE * const id, std::shared_ptr<GameEntity> entity);
    bool setEntity(GameEntity::ID_TYPE id, std::shared_ptr<GameEntity> entity);
};
