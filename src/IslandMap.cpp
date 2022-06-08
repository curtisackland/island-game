#include "IslandMap.hpp"
IslandMap::IslandMap() : GameMap(){
    
}

IslandMap::~IslandMap() {
    
}

void IslandMap::generate(int chunkX, int chunkY) {
    MapChunk *newMapChunk = new MapChunk(chunkX, chunkY);
    for (int x = 0; x < this->chunkSize; ++x) {
        for (int y = 0; y < this->chunkSize; ++y) {
            if ((sqrt((x + chunkX * this->chunkSize) * (x + chunkX * this->chunkSize) + (y + chunkY * this->chunkSize) * (y + chunkY * this->chunkSize))) < 10) {
                newMapChunk->getTile(x, y)->setDefinedTexture(0);
            } else {
                newMapChunk->getTile(x, y)->setDefinedTexture(1);
            }
        }
    }

    this->map.insert(std::pair<std::pair<int, int>, MapChunk*>(std::pair<int, int>(chunkX, chunkY), newMapChunk));
}