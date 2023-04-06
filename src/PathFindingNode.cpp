#include "PathFindingNode.hpp"

PathFindingNode::PathFindingNode(int xTile, int yTile, float hcost, float gcost, PathFindingNode *prev){
    this->tileX = xTile;
    this->tileY = yTile;
    this->hcost = hcost;
    this->gcost = gcost;
    this->fcost = hcost + gcost;
    this->prev = prev;
}

PathFindingNode::~PathFindingNode(){
    //printf("Deleted: %f\n", this->fcost);
}

