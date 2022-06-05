#include "GameMap.hpp"

GameMap::GameMap() {
    this->chunkSize = GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("chunk-size").as_uint64();
    this->generationSeed = 1;
}

GameMap::~GameMap() {

}

Tile* GameMap::getTile(int x, int y) {
    
    return this->map.at(std::pair<int, int>(floor(((float) x) / ((float)this->chunkSize)), floor(((float) x) / ((float)this->chunkSize))))->getTile(x % this->chunkSize, y % this->chunkSize);
}

void GameMap::setTile(int x, int y, Tile* tile){
    this->map.at(std::pair<int, int>(floor(((float) x) / ((float)this->chunkSize)), floor(((float) x) / ((float)this->chunkSize))))->setTile(x % this->chunkSize, y % this->chunkSize, tile);
}
