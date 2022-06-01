#pragma once
#include <SFML/Graphics.hpp>
#include "TextureFactory.hpp"
/**
 * @brief Controls all attributes of the player and its sprite
 * 
 */
class Player : public sf::Sprite{
    private:

    public:
        Player();
        ~Player();

        int getTextureWidth(); // returns the width of the texture
};