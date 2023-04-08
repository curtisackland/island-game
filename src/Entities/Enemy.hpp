#pragma once
#include <SFML/Graphics.hpp>
#include "../TextureFactory.hpp"
#include "GameEntity.hpp"
#include "../Map/GameMap.hpp"
#include "../GameConfig.hpp"
#include "../GameState/GameState.hpp"
#include "../PathFindingNode.hpp"
#include <stdio.h>
#include <queue>
#include <vector>
/**
 * @brief Controls all attributes of the Enemy and its sprite
 * 
 */
class Enemy : public GameEntity {
    private:
        std::weak_ptr<GameEntity> pathfindingTarget;
        double calculateHeuristic(int x1, int y1, int x2, int y2);
        bool static Compare(PathFindingNode *left, PathFindingNode *right);
        void addNode(int x, int y, int tx, int ty, int gcost, PathFindingNode *node, std::priority_queue<PathFindingNode*, std::vector<PathFindingNode*>, decltype(&Compare)> &fringe);
    public:
        Enemy(const std::shared_ptr<GameState>& state, std::shared_ptr<GameEntity> target, int layer);
        ~Enemy() = default;
        void releaseReferences();

        int getTextureWidth(); // returns the width of the texture
        void update();
        void draw();
        inline void setPathFindingTarget(const std::shared_ptr<GameEntity>& target) {this->pathfindingTarget = target;}
        inline std::shared_ptr<GameEntity> getPathFindingTarget();
        const boost::json::object& getMyConfigFile();
        void loadConfigs();
};
