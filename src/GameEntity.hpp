#pragma once
#include <SFML/Graphics.hpp>
#include "GameMap.hpp"

class GameEvents;

class GameEntity : public sf::Sprite {
public:
    typedef unsigned long long ID_TYPE;
private:
    static ID_TYPE top_id;
    ID_TYPE id;
    int drawLayer;
    GameEvents *eventParent;
protected:
    int currentMap;
    float speed;
public:
    GameEntity(int layer);
    ~GameEntity();
    virtual void update() = 0;
    virtual void draw() = 0;
    inline ID_TYPE getId() {return this->id;}
    inline int getMapLayer() {return this->currentMap;}
    inline int getDrawLayer() {return this->drawLayer;}
    inline void setDrawLayer(int drawLayer) {this->drawLayer = drawLayer;}
    inline void setMapLayer(int newMap) {this->currentMap = newMap;}
};
