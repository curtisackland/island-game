#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdio.h>

class Game{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape* player;

    public:
        Game();
        ~Game();

        void gameLoop();
};