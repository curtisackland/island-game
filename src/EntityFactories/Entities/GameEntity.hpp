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
    ID_TYPE getId() const {return this->id;}
    int getMapLayer() const {return this->currentMap;}
    int getDrawLayer() const {return this->drawLayer;}
    void setDrawLayer(int drawLayer) {this->drawLayer = drawLayer;}
    void setMapLayer(int newMap) {this->currentMap = newMap;}
    GameEvents *getEventParent() const {return eventParent;}
    void setEventParent(GameEvents *eventParent) {this->eventParent = eventParent;}
};
