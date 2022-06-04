#pragma once
#include <SFML/Graphics.hpp>
#include "TextureFactory.hpp"
#include "GameEntity.hpp"
#include "GameMap.hpp"
#include "GameConfig.hpp"
#include <vector>
/**
 * @brief Controls all attributes of the Enemy and its sprite
 * 
 */
class Enemy : public GameEntity {
    private:
        GameEntity* pathfindingTarget;
    public:
        Enemy(GameEntity* target, int layer);
        ~Enemy();

        int getTextureWidth(); // returns the width of the texture
        void update();
        void draw();
        inline void setPathFindingTarget(GameEntity* target) {this->pathfindingTarget = target;}
        inline GameEntity* getPathFindingTarget() {return this->pathfindingTarget;}
        const boost::json::object& getMyConfigFile();
        void loadConfigs();
};