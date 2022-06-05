#include "MapChunk.hpp"

MapChunk::MapChunk(int x, int y) {
    // This constructor needs to take in a value for position so that tiles are able to be placed properly
    this->chunkSize = GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("chunk-size").as_uint64();
    for (int i = 0; i < this->chunkSize * this->chunkSize; ++i) {
        this->tiles.push_back(Tile(x * this->chunkSize, y * this->chunkSize));
    }
}

MapChunk::~MapChunk() {

}

Tile *MapChunk::getTile(int x, int y) {

}

void MapChunk::setTile(int x, int y, Tile *tile) {
    
}