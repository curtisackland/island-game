#ifndef GameMap_h
#define GameMap_h

#include "MapChunk.hpp"
#include "GameConfig.hpp"
#include <map>
/**
 * @brief Controls all the attributes of the map: tiles, generation, etc.
 * 
 */
class GameMap{
    protected:
        //std::vector<std::vector<Tile*>*> *map; // map containing all the tiles
        int generationSeed;
        std::map<std::pair<int, int>, std::unique_ptr<MapChunk>> map;
        int const chunkSize;
        int tileSize = 30; // Tile size is based on window width (ex. 30 means tiles are size = window width/30)
    public:
        GameMap();
        ~GameMap() = default;
        virtual void generate(int chunkX, int chunkY) = 0; // Generates the map
        virtual Tile* getTile(int x, int y); // gets the tile with index x,y
        virtual void setTile(int x, int y, Tile* tile); // sets the tile at index x,y
        //virtual int getWidth(); // returns width of the map
        //virtual int getHeight(); // returns height of the map
};

#endif 
