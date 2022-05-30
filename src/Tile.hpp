#pragma once
#include <string.h>
#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite{
    private:
        sf::Texture* texture;
        bool walkable;
    public:
        Tile(int id, float x, float y);
        ~Tile();

        int getTextureWidth(); // Add height when objects are no longer just squares
        bool isWalkable();
};