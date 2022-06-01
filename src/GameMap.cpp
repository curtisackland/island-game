#include "GameMap.hpp"

Tile* GameMap::getTile(int x, int y){
    return (*(*this->map)[x])[y];
}

void GameMap::setTile(int x, int y, Tile* tile){
    (*(*this->map)[x])[y] = tile;
}

int GameMap::getWidth(){
    return (*this->map).size();
}

int GameMap::getHeight(){
    return (*(*this->map)[0]).size();
}