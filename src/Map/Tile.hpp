#pragma once
#include <string.h>
#include <SFML/Graphics.hpp>
#include "GameState/TextureFactory.hpp"
#include "GameConfig.hpp"

/**
 * @brief Controls all attributes of the tile and its sprite
 * 
 */
class Tile : public sf::Sprite{
private:
    bool walkable; // Is the tile able to be walked on
    const float tileSize;

public:
    Tile(int xIndex, int yIndex);
    Tile(float x, float y);
    Tile(int id, float x, float y);
    ~Tile();

    void setDefinedTexture(int texureNumber);
    int getTextureWidth(); // Add height when objects are no longer just squares
    bool isWalkable(); // Returns true if the tile is able to be walked on
};
