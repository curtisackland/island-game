#ifndef GameMap_h
#define GameMap_h

#include "Tile.hpp"
#include <vector>

class GameMap{
    protected:
        std::vector<std::vector<Tile*>*> *map; // maybe Tiles need to be pointers
        int tileSize = 30;
    public:

        void generate(int width, int height, sf::RenderWindow* window);
        virtual Tile* getTile(int x, int y);
        virtual void setTile(int x, int y, Tile* tile);
        virtual int getWidth();
        virtual int getHeight();
};

#endif 