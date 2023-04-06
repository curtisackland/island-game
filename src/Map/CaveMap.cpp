#include "CaveMap.hpp"

CaveMap::CaveMap() : GameMap(){
    this->layeredNoise = std::make_unique<LayeredNoise2D>();
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(651, 0.1, 30, 30));
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(127643, 0.2, 10, 10));
    layeredNoise->addLayer(new NoiseBuilder2DPerlin(1230, 0.4, 5, 5));
}

void CaveMap::generate(int chunkX, int chunkY) {
    auto newMapChunk = std::make_unique<MapChunk>(chunkX, chunkY);
    for (int x = 0; x < this->chunkSize; ++x) {
        for (int y = 0; y < this->chunkSize; ++y) {
            double val = layeredNoise->noise(((double) chunkX) + (((double) x) / ((double) this->chunkSize)), ((double) chunkY) + (((double) y) / ((double) this->chunkSize)));
            if (val > 40) {
                newMapChunk->getTile(x, y)->setDefinedTexture(0);
            } else {
                newMapChunk->getTile(x, y)->setDefinedTexture(1);
            }
        }
    }

    this->map.insert(std::pair<std::pair<int, int>, std::unique_ptr<MapChunk>>(std::pair<int, int>(chunkX, chunkY), std::move(newMapChunk)));
}
