#pragma once
#include <SFML/Graphics.hpp>
class GameEntity : public sf::Sprite {
public:
    typedef unsigned long long ID_TYPE;
private:
    static ID_TYPE top_id;
    ID_TYPE id;
    int currentMap;
public:
    GameEntity();
    ~GameEntity();
    virtual void update() = 0;
    inline ID_TYPE getId() {return this->id;}
    inline int getMapLayer() {return this->currentMap;}
    inline void setMapLayer(int newMap) {this->currentMap = newMap;}
};
