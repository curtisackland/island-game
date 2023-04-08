#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Entities/Player.hpp"
#include "GameState/GameState.hpp"
#include "Map/GameMap.hpp"
#include "Map/IslandMap.hpp"
#include "Map/CaveMap.hpp"
#include "Map/Tile.hpp"
#include <stdio.h>
#include "GameConfig.hpp"
#include "GameEvents.hpp"
#include "Entities/GameEntity.hpp"
#include "Entities/Enemy.hpp"

#include <math.h>
#include <vector>
/**
 * @brief Controls the game
 * 
 */
class Game {
    private:
        std::shared_ptr<GameState> state;

        const int tilesPerWindowWidth; // Tile size is based on window width (ex. 30 means tiles are size = window width/30)
        std::shared_ptr<Player> player; // The player
        std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemies;

        sf::Clock clock; // Game clock
        float deltaTime; // Time since last frame

        int currentMap;

        GameEvents eventSystem;
    public:
        Game();
        ~Game();
        void childrenReleaseReferences();

        void gameLoop(); // Runs the game
        void drawMap(); // Draws tiles that are in the player's fov
        std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> spawnEnemiesOnMap(const int layer);
};
