#include "MapChunk.hpp"

MapChunk::MapChunk(int chunkX, int chunkY) {
    // This constructor needs to take in a value for position so that tiles are able to be placed properly
    printf("New chunk at %d %d\n", chunkX, chunkY);
    for (int x = 0; x < this->chunkSize; ++x) {
        for (int y = 0; y < this->chunkSize; ++y) {
            tiles[x][y] = new Tile(x + this->chunkSize * chunkX, y + this->chunkSize * chunkY);
        }
    }
}

MapChunk::~MapChunk() {
    for (auto x : this->tiles) {
        for (auto y : x) {
            delete y;
            y = nullptr;
        }
    }
}

Tile *MapChunk::getTile(int x, int y) {
    return this->tiles[x][y];
}

void MapChunk::setTile(int x, int y, Tile *tile) {
    assert("Not yet implemented");
    printf("%d %d %ld", x, y, (long) tile);
}
