#pragma once
#include "../src/Entities/GameEntity.hpp"
class GameEntityTest : public GameEntity {
private:
    bool internalVariable = false;
    bool internalVariable2 = false;
public:
    GameEntityTest(int layer);
    ~GameEntityTest();
    void update();
    void draw();
    inline bool getInternalVariable(){return this->internalVariable;}
    inline bool getInternalVariable2(){return this->internalVariable2;}
};
