#pragma once
#include <SFML/Graphics.hpp>
#include "../GameConfig.hpp"
#include "GameEntity.hpp"
#include "../GameState/GameState.hpp"
#include "../Map/GameMap.hpp"
#include "../TextureFactory.hpp"
#include <math.h>
/**
 * @brief Controls all attributes of the player and its sprite
 * 
 */
class Player : public GameEntity {
    private:
        const float diagonalScalar = sin(45); // Scalar for moving diagonally
    public:
        Player(GameEntity::ID_TYPE id, int layer);
        ~Player() = default;
        void releaseReferences();

        int getTextureWidth(); // returns the width of the texture
        void update();
        void draw();
        const boost::json::object& getMyConfigFile();
        void loadConfigs();
};
