#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.hpp"
#include "GameMap.hpp"
#include "IslandMap.hpp"
#include "Tile.hpp"
#include <stdio.h>
#include "GameConfig.hpp"
#include "GameEvents.hpp"
#include "GameEntity.hpp"
#include "Enemy.hpp"
#include "MainWindow.hpp"
#include "MainView.hpp"
#include <math.h>
#include <vector>
/**
 * @brief Controls the game
 * 
 */
class Game {
    private:
        const int tileSize = 30; // Tile size is based on window width (ex. 30 means tiles are size = window width/30)
        Player* player; // The player
        sf::Clock clock; // Game clock
        float deltaTime; // Time since last frame
        int currentMap;
        sf::View* view; // View of the map, focussed on player
        std::vector<Enemy*>* enemies;
        GameEvents eventSystem;
    public:
        Game();
        ~Game();

        void gameLoop(); // Runs the game
        void drawMap(); // Draws tiles that are in the player's fov
        std::vector<Enemy*> * spawnEnemiesOnMap(int layer);
};