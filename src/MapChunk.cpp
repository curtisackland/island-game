#include "MapChunk.hpp"
MapChunk::MapChunk() {
    // This constructor needs to take in a value for position so that tiles are able to be placed properly
    this->chunkSize = GameConfig::getInstance().getJson("const-settings.json").at("map").at("chunk-size").as_uint64();
    for (int i = 0; i < this->chunkSize * this->chunkSize; ++i) {
        this->tiles.push_back(Tile());
    }
}

MapChunk::~MapChunk() {

}

Tile *MapChunk::getTile(int x, int y) {

}

void MapChunk::setTile(int x, int y, Tile *tile) {
    
}