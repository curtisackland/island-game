#include <stdio.h>
class PathFindingNode{
    private:
        float hcost;
        float gcost;
        float fcost;
        PathFindingNode *prev = nullptr;
        int tileX;
        int tileY;
    public:
        PathFindingNode(int xTile, int yTile, float hcost, float gcost, PathFindingNode *prev = nullptr);
        ~PathFindingNode();
        float getHCost(){return hcost;}
        void setHCost(float h){hcost = h;}
        float getGCost(){return gcost;}
        void setGCost(float g){gcost = g;}
        float getFCost(){return fcost;}
        void setFCost(float f){fcost = f;}
        void setPreviousNode(PathFindingNode *p){prev = p;}
        PathFindingNode* getPreviousNode(){return prev;}
        int getTileX(){return tileX;}
        int getTileY(){return tileY;}
};