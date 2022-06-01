#pragma once
#include <unordered_map>
#include "GameEntity.hpp"

class GameEvents {
private:
    std::unordered_map<int, GameEntity*> updateEntitiesList;
public:
    GameEvents();
    ~GameEvents();

    void addUpdateEntity(GameEntity *entity);
    void notifyUpdateEntities();
    bool contains(GameEntity *entity);
    void removeEntity(GameEntity *entity);
    void notifyAll();
};