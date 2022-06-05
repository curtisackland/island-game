#include "Tile.hpp"
#include "GameConfig.hpp"
#include <vector>

class MapChunk {
private:
    int chunkSize;
    std::vector<Tile> tiles;
    
public:
    MapChunk(int x, int y);
    ~MapChunk();
    Tile* getTile(int x, int y);
    void setTile(int x, int y, Tile *tile);
};