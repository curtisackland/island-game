#pragma once
#include <SFML/Graphics.hpp>
#include "GameConfig.hpp"
#include "GameEntity.hpp"
#include "MainWindow.hpp"
#include "GameState.hpp"
#include "GameMap.hpp"
#include "TextureFactory.hpp"
#include <math.h>
/**
 * @brief Controls all attributes of the player and its sprite
 * 
 */
class Player : public GameEntity {
    private:
        const float diagonalScalar = sin(45); // Scalar for moving diagonally
    public:
        Player(int layer);
        ~Player();

        int getTextureWidth(); // returns the width of the texture
        void update();
        void draw();
        const boost::json::object& getMyConfigFile();
        void loadConfigs();
};