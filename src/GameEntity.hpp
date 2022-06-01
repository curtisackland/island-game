#pragma once
class GameEntity {
public:
    typedef unsigned long long ID_TYPE;
private:
    static ID_TYPE top_id;
    ID_TYPE id;
public:
    GameEntity();
    ~GameEntity();
    virtual void update() = 0;
    inline ID_TYPE getId() {return this->id;}
};
