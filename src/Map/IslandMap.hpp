#pragma once
#include "GameMap.hpp"
#include "Tile.hpp"
#include "../Noise/LayeredNoise2D.hpp"
#include "../Noise/Perlin/Noise2DPerlin.hpp"
#include "../Noise/HighCenter/Noise2DHighCenter.hpp"

class IslandMap : public GameMap{
private:
    LayeredNoise2D *layeredNoise;
public:
    IslandMap();
    ~IslandMap() = default;

    void generate(int chunkX, int chunkY);
};
