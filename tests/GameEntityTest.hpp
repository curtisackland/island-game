#pragma once
#include "../mainTest.hpp"
class GameEntityTest : public GameEntity {
private:
    bool internalVariable = false;
public:
    void update();
    inline bool getInternalVariable(){return this->internalVariable;}
};