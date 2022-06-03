#pragma once
#include <SFML/Graphics.hpp>
#include "TextureFactory.hpp"
#include "GameEntity.hpp"
/**
 * @brief Controls all attributes of the player and its sprite
 * 
 */
class Player : public GameEntity {
    private:

    public:
        Player();
        ~Player();

        int getTextureWidth(); // returns the width of the texture
        void update();
};