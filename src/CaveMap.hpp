#pragma once
#include <memory>
#include "GameMap.hpp"
#include "Tile.hpp"
#include "MainWindow.hpp"
#include "Noise/LayeredNoise2D.hpp"
#include "Noise/Perlin/NoiseBuilder2DPerlin.hpp"

class CaveMap : public GameMap{
private:
    LayeredNoise2D *layeredNoise;
public:
    CaveMap();
    ~CaveMap();
    
    void generate(int chunkX, int chunkY);
};
