#include "IslandMap.hpp"

IslandMap::IslandMap() : GameMap(){
    this->layeredNoise = new LayeredNoise2D();
    layeredNoise->addLayer(new NoiseBuilder2DHighCenter(2, 50, 0, 0, 0));
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(86747272, 0.2, 20, 20));
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(27074768, 0.4, 10, 10));
}

IslandMap::~IslandMap() {
    delete this->layeredNoise;
    this->layeredNoise = nullptr;
}

void IslandMap::generate(int chunkX, int chunkY) {
    MapChunk *newMapChunk = new MapChunk(chunkX, chunkY);
    for (int x = 0; x < this->chunkSize; ++x) {
        for (int y = 0; y < this->chunkSize; ++y) {
            double val = layeredNoise->noise(((double) chunkX) + (((double) x) / ((double) this->chunkSize)), ((double) chunkY) + (((double) y) / ((double) this->chunkSize)));
            if (val > 85) {
                newMapChunk->getTile(x, y)->setDefinedTexture(1);
            } else if (val > 42) {
                newMapChunk->getTile(x, y)->setDefinedTexture(0);
            } else if (val > 40) {
                newMapChunk->getTile(x, y)->setDefinedTexture(3);
            } else {
                newMapChunk->getTile(x, y)->setDefinedTexture(2);
            }
        }
    }

    this->map.insert(std::pair<std::pair<int, int>, MapChunk*>(std::pair<int, int>(chunkX, chunkY), newMapChunk));
}