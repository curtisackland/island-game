#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "GameMap.hpp"
#include "IslandMap.hpp"
#include "Tile.hpp"
#include <stdio.h>
#include <math.h>

class Game{
    private:
        const int tileSize = 30;
        sf::RenderWindow* window;
        Player* player;
        sf::Texture* playerTexture;
        sf::Clock clock;
        float deltaTime;
        IslandMap* island; // Island map
        sf::View* view;
        sf::Texture* block;
        sf::Texture* terrain;

    public:
        Game();
        ~Game();

        void gameLoop();
        void drawMap(); // Draws tiles that are in the player's fov
};