#pragma once
#include <string.h>
#include <SFML/Graphics.hpp>
/**
 * @brief Controls all attributes of the tile and its sprite
 * 
 */
class Tile : public sf::Sprite{
    private:
        sf::Texture* texture; // Texture of the tile
        bool walkable; // Is the tile able to be walked on
    public:
        Tile(int id, float x, float y);
        ~Tile();

        int getTextureWidth(); // Add height when objects are no longer just squares
        bool isWalkable(); // Returns true if the tile is able to be walked on
};