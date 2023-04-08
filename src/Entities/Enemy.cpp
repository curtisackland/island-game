#include "Enemy.hpp"

Enemy::Enemy(std::shared_ptr<GameState> state, std::shared_ptr<GameEntity> target, int layer) : GameEntity(state, layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/enemy.png"));
    loadConfigs();
    this->setPathFindingTarget(target);
}

int Enemy::getTextureWidth(){
    return this->getTexture()->getSize().x;
}

bool Enemy::Compare(PathFindingNode *left, PathFindingNode *right){
    return left->getFCost() > right->getFCost();
}

void Enemy::update() {
    // pixel position of target
    double targetX = pathfindingTarget->getPosition().x;
    double targetY = pathfindingTarget->getPosition().y;

    double scaleBacktoPosition = this->gameStatePtr->getMainView()->getSize().x / GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double();
    //tile position of target
    int targetTileX = floor(pathfindingTarget->getPosition().x/scaleBacktoPosition);
    int targetTileY = floor(pathfindingTarget->getPosition().y/scaleBacktoPosition);

    std::priority_queue<PathFindingNode*, std::vector<PathFindingNode*>, decltype(&Compare)> fringe(Compare);
    int startTileX = floor(this->getPosition().x/scaleBacktoPosition);
    int startTileY = floor(this->getPosition().y/scaleBacktoPosition);

    PathFindingNode *startNode = new PathFindingNode(
        startTileX, 
        startTileY, 
        calculateHeuristic(startTileX, startTileY, targetTileX, targetTileY),
        0,
        nullptr
    );
    
    fringe.push(startNode);
    
    bool found = false;
    PathFindingNode *finalNode = nullptr;
    while(!found){
        if (fringe.empty()){
            printf("Could not find target\n");
            return;
        }

        PathFindingNode *currentNode = fringe.top();
        fringe.pop();

        if(currentNode->getTileX() == targetTileX && currentNode->getTileY() == targetTileY){
            finalNode = currentNode;
            found = true;
        } else {
            addNode(currentNode->getTileX() + 1, currentNode->getTileY(), targetTileX, targetTileY, currentNode->getGCost() + 1, currentNode, fringe);
            addNode(currentNode->getTileX() - 1, currentNode->getTileY(), targetTileX, targetTileY, currentNode->getGCost() + 1, currentNode, fringe);
            addNode(currentNode->getTileX(), currentNode->getTileY() + 1, targetTileX, targetTileY, currentNode->getGCost() + 1, currentNode, fringe);
            addNode(currentNode->getTileX(), currentNode->getTileY() - 1, targetTileX, targetTileY, currentNode->getGCost() + 1, currentNode, fringe);
            addNode(currentNode->getTileX() + 1, currentNode->getTileY() + 1, targetTileX, targetTileY, currentNode->getGCost() + sqrt(2), currentNode, fringe);
            addNode(currentNode->getTileX() + 1, currentNode->getTileY() - 1, targetTileX, targetTileY, currentNode->getGCost() + sqrt(2), currentNode, fringe);
            addNode(currentNode->getTileX() - 1, currentNode->getTileY() + 1, targetTileX, targetTileY, currentNode->getGCost() + sqrt(2), currentNode, fringe);
            addNode(currentNode->getTileX() - 1, currentNode->getTileY() - 1, targetTileX, targetTileY, currentNode->getGCost() + sqrt(2), currentNode, fringe);
        }
    }
    
    float rot;
    if(startNode->getTileX() == finalNode->getTileX() && startNode->getTileY() == finalNode->getTileY()){
        rot = M_PI - atan2(targetX - this->getPosition().x, targetY - this->getPosition().y);
    } else {
        while(finalNode->getPreviousNode()->getTileX() != startNode->getTileX() || finalNode->getPreviousNode()->getTileY() != startNode->getTileY()){
            PathFindingNode *temp = finalNode;
            finalNode = finalNode->getPreviousNode();
            delete temp;
        }
        
        float positionX = this->getPosition().x;
        float positionY = this->getPosition().y;

        rot = M_PI - atan2((finalNode->getTileX() * scaleBacktoPosition + scaleBacktoPosition/2) - positionX, (finalNode->getTileY() * scaleBacktoPosition + scaleBacktoPosition/2) - positionY);
    }
    
    //delete pathfinding nodes
    while(!fringe.empty()){
        PathFindingNode *node = fringe.top();
        fringe.pop();
        delete node;
    }

    this->setRotation(rot * (180/M_PI));
    this->move(this->gameStatePtr->getTiming().getDeltaTime()*this->speed*sin(rot), -this->gameStatePtr->getTiming().getDeltaTime()*this->speed*cos(rot));
}

void Enemy::draw() {
    this->gameStatePtr->getMainWindow()->draw(*this);
}

const boost::json::object& Enemy::getMyConfigFile() {
    return GameConfig::getInstance().getJson("resources/configs/enemy.json");
}

void Enemy::loadConfigs() {
    this->speed = this->getMyConfigFile().at("speed").as_double();
    this->setTexture(*TextureFactory::getTexture(this->getMyConfigFile().at("default_texture").as_string().c_str()));
}

double Enemy::calculateHeuristic(int x1, int y1, int x2, int y2){
    int deltaY = abs(y2 - y1);
    int deltaX = abs(x2 - x1);
    return sqrt(deltaY*deltaY + deltaX*deltaX);
}

void Enemy::addNode(int x, int y, int targetX, int targetY, int gcost, PathFindingNode *node, std::priority_queue<PathFindingNode*, std::vector<PathFindingNode*>, decltype(&Compare)> &fringe){
    if(this->gameStatePtr->getMaps()->at(this->currentMap)->getTile(x, y)->isWalkable()){
        this->gameStatePtr->getMaps()->at(this->currentMap)->getTile(x, y)->setDefinedTexture(3);
        fringe.push(new PathFindingNode(
            x, 
            y,
            calculateHeuristic(x, y, targetX, targetY),
            gcost,
            node
        ));
    }
}
