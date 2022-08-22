#pragma once
#include <SFML/Graphics.hpp>
#include "TextureFactory.hpp"
#include "GameEntity.hpp"
#include "GameMap.hpp"
#include "GameConfig.hpp"
#include "MainWindow.hpp"
#include "GameState.hpp"
#include "PathFindingNode.hpp"
#include <stdio.h>
#include <queue>
#include <vector>
/**
 * @brief Controls all attributes of the Enemy and its sprite
 * 
 */
class Enemy : public GameEntity {
    private:
        GameEntity* pathfindingTarget;
        float calculateHeuristic(int x1, int y1, int x2, int y2);
        bool static Compare(PathFindingNode *left, PathFindingNode *right);
        void addNode(int x, int y, int tx, int ty, int gcost, PathFindingNode *node, std::priority_queue<PathFindingNode*, std::vector<PathFindingNode*>, decltype(&Compare)> &fringe);
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