#pragma once
#include <memory>
#include "GameMap.hpp"
#include "Tile.hpp"
#include "../Noise/LayeredNoise2D.hpp"
#include "../Noise/Perlin/Noise2DPerlin.hpp"

class CaveMap : public GameMap{
private:
    std::unique_ptr<LayeredNoise2D> layeredNoise;
public:
    CaveMap();
    ~CaveMap() = default;
    
    void generate(int chunkX, int chunkY);
};
