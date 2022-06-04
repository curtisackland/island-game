#pragma once
#include "GameMap.hpp"
#include "Tile.hpp"
#include "MainWindow.hpp"

class IslandMap : public GameMap{
    private:

    public:
        IslandMap();
        ~IslandMap();

        void generate(int width, int height);
};