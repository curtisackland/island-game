#include "GameMap.hpp"

GameMap:: GameMap() : chunkSize(GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("chunk-size").as_int64()) {
    this->generationSeed = 1;
}

Tile* GameMap::getTile(int x, int y) {
    int chunkX = floor(((float) x) / ((float)this->chunkSize)); // float division so that rounding works properly
    int chunkY = floor(((float) y) / ((float)this->chunkSize));
    if (this->map.find(std::pair<int, int>(chunkX, chunkY)) == this->map.end()) {
        generate(chunkX, chunkY);
    }
    int insideChunkX = x % this->chunkSize;
    int insideChunkY = y % this->chunkSize;

    insideChunkX += this->chunkSize * (insideChunkX < 0);
    insideChunkY += this->chunkSize * (insideChunkY < 0);

    return this->map.at(std::pair<int, int>(chunkX, chunkY))->getTile(insideChunkX, insideChunkY);
}

void GameMap::setTile(int x, int y, Tile* tile){
    int chunkX = floor(((float) x) / ((float)this->chunkSize));
    int chunkY = floor(((float) y) / ((float)this->chunkSize));
    int insideChunkX = x % this->chunkSize;
    int insideChunkY = y % this->chunkSize;

    insideChunkX += this->chunkSize * (insideChunkX < 0);
    insideChunkY += this->chunkSize * (insideChunkY < 0);
    this->map.at(std::pair<int, int>(chunkX, chunkY))->setTile(insideChunkX, insideChunkY, tile);
}
