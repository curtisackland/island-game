#pragma once
#include <memory>
#include <unordered_map>
#include "../Entities/GameEntity.hpp"

class EntityManager {
private:
    static GameEntity::ID_TYPE topID;
    std::unordered_map<GameEntity::ID_TYPE, std::unique_ptr<GameEntity>> entities;

public:
    EntityManager() = default;
    ~EntityManager() = default;

    GameEntity::ID_TYPE generateID();
    inline GameEntity * const getEntity(GameEntity::ID_TYPE id);
    inline GameEntity::ID_TYPE setEntity(std::unique_ptr<GameEntity> entity);
    inline void setEntity(GameEntity::ID_TYPE id, std::unique_ptr<GameEntity> entity);
};
