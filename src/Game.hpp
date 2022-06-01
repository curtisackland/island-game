#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "GameMap.hpp"
#include "IslandMap.hpp"
#include "Tile.hpp"
#include <stdio.h>
#include <math.h>
/**
 * @brief Controls the game
 * 
 */
class Game{
    private:
        const int tileSize = 30; // Tile size is based on window width (ex. 30 means tiles are size = window width/30)
        const float diagonalScalar = sin(45); // Scalar for moving diagonally
        sf::RenderWindow* window; // The window where the game is played and rendered
        Player* player; // The player
        sf::Texture* playerTexture; // The player's texture
        sf::Clock clock; // Game clock
        float deltaTime; // Time since last frame
        IslandMap* island; // Island map
        sf::View* view; // View of the map, focussed on player

    public:
        Game();
        ~Game();

        void gameLoop(); // Runs the game
        void drawMap(); // Draws tiles that are in the player's fov
};