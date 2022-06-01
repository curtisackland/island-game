#pragma once
#include <SFML/Graphics.hpp>
/**
 * @brief Controls all attributes of the player and its sprite
 * 
 */
class Player : public sf::Sprite{
    private:
        sf::Texture* texture;
    public:
        Player();
        ~Player();

        int getTextureWidth(); // returns the width of the texture
};