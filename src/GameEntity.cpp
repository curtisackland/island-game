#include "GameEntity.hpp"

unsigned long long GameEntity::top_id = 0;

GameEntity::GameEntity(int layer) {
    this->id = top_id++;
    this->setMapLayer(layer);
}

GameEntity::~GameEntity() {
    
}
