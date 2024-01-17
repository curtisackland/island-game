#pragma once
#include "EntityFactories/Entities/GameEntity.hpp"
class GameEntityTest : public GameEntity {
private:
    bool internalVariable = false;
    bool internalVariable2 = false;
public:
    GameEntityTest(int id, int layer);
    ~GameEntityTest();
    void update();
    void draw();
    bool getInternalVariable(){return this->internalVariable;}
    bool getInternalVariable2(){return this->internalVariable2;}
};
