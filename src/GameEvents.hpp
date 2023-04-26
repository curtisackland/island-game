#pragma once
#include <memory>
#include <unordered_map>

class GameEntity;

class GameEvents {
public:
    typedef std::unordered_map<int, std::shared_ptr<GameEntity>> ENTITY_MAP;
    typedef ENTITY_MAP UPDATE_ENTITIES_LIST_TYPE;
    typedef std::unordered_map<int, ENTITY_MAP> DRAW_ENTITIES_LIST_TYPE;
private:
    UPDATE_ENTITIES_LIST_TYPE updateEntitiesList;
    DRAW_ENTITIES_LIST_TYPE drawEntitiesList;
public:
    

    GameEvents() = default;
    ~GameEvents();
    void releaseReferences();

    void addUpdateEntity(std::shared_ptr<GameEntity> entity);
    void notifyUpdateEntities();
    bool updateListContains(const GameEntity& entity);
    void removeUpdateEntity(const GameEntity& entity);

    void addDrawEntity(std::shared_ptr<GameEntity> entity, int layer);
    void notifyDrawEntities();
    bool drawListContains(const GameEntity& entity);
    void removeDrawEntity(const GameEntity& entity);
    
    ENTITY_MAP& getDrawLayerMap(const int layer);

    void notifyAll();
    void removeFromAll(const GameEntity& entity);
};
