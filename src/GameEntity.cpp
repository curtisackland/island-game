#include "GameEntity.hpp"

unsigned long long GameEntity::top_id = 0;

GameEntity::GameEntity() {
    this->id = top_id++;
}

GameEntity::~GameEntity() {
    
}
