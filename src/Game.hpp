#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>
#include <math.h>

class Game{
    private:
        const int tileSize = 30;
        sf::RenderWindow* window;
        sf::Sprite* player;
        sf::Texture* playerTexture;
        sf::Clock clock;
        float deltaTime;
        int** map;
        sf::Sprite*** mapShape;
        sf::View* view;
        sf::Texture* block;
        sf::Texture* terrain;

    public:
        Game();
        ~Game();

        void gameLoop();
};