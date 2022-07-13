#include "CaveMap.hpp"
CaveMap::CaveMap() : GameMap(){
    
}

CaveMap::~CaveMap() {
    
}

void CaveMap::generate(int chunkX, int chunkY) {
    Noise2DPerlin n;
    MapChunk *newMapChunk = new MapChunk(chunkX, chunkY);
    for (int x = 0; x < this->chunkSize; ++x) {
        for (int y = 0; y < this->chunkSize; ++y) {
            if (n.noise(((double) chunkX) + (((double) x) / ((double) this->chunkSize)), ((double) chunkY) + (((double) y) / ((double) this->chunkSize))) > 0) {
                newMapChunk->getTile(x, y)->setDefinedTexture(0);
            } else {
                newMapChunk->getTile(x, y)->setDefinedTexture(1);
            }
        }
    }

    this->map.insert(std::pair<std::pair<int, int>, MapChunk*>(std::pair<int, int>(chunkX, chunkY), newMapChunk));
}