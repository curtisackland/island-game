#pragma once
#include <SFML/Graphics.hpp>
#include "TextureFactory.hpp"
#include "GameEntity.hpp"
#include "GameMap.hpp"
#include <vector>
/**
 * @brief Controls all attributes of the Enemy and its sprite
 * 
 */
class Enemy : public GameEntity {
    private:
        GameEntity* pathfindingTarget;
        std::vector<GameMap*>* maps;
    public:
        Enemy(GameEntity* target, std::vector<GameMap*>* maps, int layer);
        ~Enemy();

        int getTextureWidth(); // returns the width of the texture
        void update();
        inline void setPathFindingTarget(GameEntity* target) {this->pathfindingTarget = target;}
        inline GameEntity* getPathFindingTarget() {return this->pathfindingTarget;}
};