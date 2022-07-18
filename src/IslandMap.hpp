#pragma once
#include "GameMap.hpp"
#include "Tile.hpp"
#include "MainWindow.hpp"
#include "Noise/LayeredNoise2D.hpp"
#include "Noise/Perlin/NoiseBuilder2DPerlin.hpp"
#include "Noise/HighCenter/NoiseBuilder2DHighCenter.hpp"

class IslandMap : public GameMap{
private:
    LayeredNoise2D *layeredNoise;
public:
    IslandMap();
    ~IslandMap();

    void generate(int chunkX, int chunkY);
};