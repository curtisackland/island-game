#include "Tile.hpp"
#include "../GameConfig.hpp"
#include <vector>
#include <array>
class MapChunk {
private:
    static const int chunkSize = 10;
    std::array<std::array<Tile*, chunkSize>, chunkSize> tiles;
    
public:
    MapChunk(int x, int y);
    ~MapChunk();
    Tile* getTile(int x, int y);
    void setTile(int x, int y, Tile *tile);
};
