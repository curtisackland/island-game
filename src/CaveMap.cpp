#include "CaveMap.hpp"
CaveMap::CaveMap() : GameMap(){
    
}

CaveMap::~CaveMap() {
    
}

void CaveMap::generate(int chunkX, int chunkY) {
    LayeredNoise2D layeredNoise(0, 100);
    std::shared_ptr<Noise2DPerlin> layer1 = std::make_shared<Noise2DPerlin>(0, 0.1, 0, 100);
    layeredNoise.addLayer(layer1);
    MapChunk *newMapChunk = new MapChunk(chunkX, chunkY);
    for (int x = 0; x < this->chunkSize; ++x) {
        for (int y = 0; y < this->chunkSize; ++y) {
            if (layeredNoise.noise(((double) chunkX) + (((double) x) / ((double) this->chunkSize)), ((double) chunkY) + (((double) y) / ((double) this->chunkSize))) > 10) {
                newMapChunk->getTile(x, y)->setDefinedTexture(0);
            } else {
                newMapChunk->getTile(x, y)->setDefinedTexture(1);
            }
        }
    }

    this->map.insert(std::pair<std::pair<int, int>, MapChunk*>(std::pair<int, int>(chunkX, chunkY), newMapChunk));
}