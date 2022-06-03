#pragma once
#include <SFML/Graphics.hpp>
#include "TextureFactory.hpp"
#include "GameEntity.hpp"
/**
 * @brief Controls all attributes of the Enemy and its sprite
 * 
 */
class Enemy : public GameEntity, public sf::Sprite{
    private:

    public:
        Enemy(int layer);
        ~Enemy();

        int getTextureWidth(); // returns the width of the texture
        void update();
};