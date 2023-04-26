#pragma once
#include <SFML/Graphics.hpp>

class GameEvents;

class GameEntity : public sf::Sprite {
public:
    typedef unsigned long long ID_TYPE;
private:
    ID_TYPE id;
    int drawLayer;
    GameEvents *eventParent;
protected:
    int currentMap;
    float speed;
public:
    GameEntity(ID_TYPE id, int layer);
    ~GameEntity() = default;
    void releaseReferences();

    virtual void update() = 0;
    virtual void draw() = 0;
    inline ID_TYPE getId() const {return this->id;}
    inline int getMapLayer() const {return this->currentMap;}
    inline int getDrawLayer() const {return this->drawLayer;}
    inline void setDrawLayer(int drawLayer) {this->drawLayer = drawLayer;}
    inline void setMapLayer(int newMap) {this->currentMap = newMap;}
    inline GameEvents *getEventParent() const {return eventParent;}
    inline void setEventParent(GameEvents *eventParent) {this->eventParent = eventParent;}
};
