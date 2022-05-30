#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite{
    private:
        sf::Texture* texture;
    public:
        Player();
        ~Player();

        int getTextureWidth();
};