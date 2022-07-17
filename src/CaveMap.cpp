#include "CaveMap.hpp"

CaveMap::CaveMap() : GameMap(){
    this->layeredNoise = new LayeredNoise2D();
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(0, 0.4, 30, 30));
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(127643, 0.4, 10, 10));
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(1230, 0.4, 5, 5));
}

CaveMap::~CaveMap() {
    delete this->layeredNoise;
}

void CaveMap::generate(int chunkX, int chunkY) {
    MapChunk *newMapChunk = new MapChunk(chunkX, chunkY);
    for (int x = 0; x < this->chunkSize; ++x) {
        for (int y = 0; y < this->chunkSize; ++y) {
            double val = layeredNoise->noise(((double) chunkX) + (((double) x) / ((double) this->chunkSize)), ((double) chunkY) + (((double) y) / ((double) this->chunkSize)));
            if (val > 35) {
                newMapChunk->getTile(x, y)->setDefinedTexture(0);
            } else {
                newMapChunk->getTile(x, y)->setDefinedTexture(1);
            }
        }
    }

    this->map.insert(std::pair<std::pair<int, int>, MapChunk*>(std::pair<int, int>(chunkX, chunkY), newMapChunk));
}
