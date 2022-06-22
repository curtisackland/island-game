#pragma once
#include <map>
#include <unordered_map>

class GameEntity;

class GameEvents {
public:
    typedef std::unordered_map<int, GameEntity*> UPDATE_ENTITIES_LIST_TYPE;
    typedef std::map<int, UPDATE_ENTITIES_LIST_TYPE> DRAW_ENTITIES_LIST_TYPE;
private:
    UPDATE_ENTITIES_LIST_TYPE updateEntitiesList;
    DRAW_ENTITIES_LIST_TYPE drawEntitiesList;
public:
    

    GameEvents();
    ~GameEvents();

    void addUpdateEntity(GameEntity *entity);
    void notifyUpdateEntities();
    bool updateListContains(GameEntity *entity);
    void removeUpdateEntity(GameEntity *entity);

    void addDrawEntity(GameEntity *entity, int layer);
    void notifyDrawEntities();
    bool drawListContains(GameEntity *entity);
    void removeDrawEntity(GameEntity *entity);
    

    void notifyAll();
    void removeFromAll(GameEntity *entity);
};