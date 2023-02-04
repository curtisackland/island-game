#include "Enemy.hpp"

Enemy::Enemy(GameEntity* target, int layer) : GameEntity(layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/enemy.png"));
    loadConfigs();
    this->setPathFindingTarget(target);
}

Enemy::~Enemy(){

}

int Enemy::getTextureWidth(){
    return this->getTexture()->getSize().x;
}

bool Enemy::Compare(PathFindingNode *left, PathFindingNode *right){
    return left->getFCost() > right->getFCost();
}

void Enemy::update() {
    // pixel position of target
    float tx = pathfindingTarget->getPosition().x;
    float ty = pathfindingTarget->getPosition().y;

    //tile position of target
    int targetTileX = pathfindingTarget->getPosition().x/MainView::getInstance().getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double();
    int targetTileY = pathfindingTarget->getPosition().y/MainView::getInstance().getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double();

    std::priority_queue<PathFindingNode*, std::vector<PathFindingNode*>, decltype(&Compare)> fringe(Compare);
    int startTileX = this->getPosition().x/MainView::getInstance().getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double();
    int startTileY = this->getPosition().y/MainView::getInstance().getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double();

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
        rot = M_PI - atan2(tx - this->getPosition().x, ty - this->getPosition().y);
    } else {
        while(finalNode->getPreviousNode()->getTileX() != startNode->getTileX() || finalNode->getPreviousNode()->getTileY() != startNode->getTileY()){
            PathFindingNode *temp = finalNode;
            finalNode = finalNode->getPreviousNode();
            delete temp;
        }
        float scaleBacktoPosition = MainView::getInstance().getSize().x / GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double();
        
        float positionX = this->getPosition().x;
        float positionY = this->getPosition().y;

        // negative coords need position to be scaled back one tile for trig function to work properly
        if (finalNode->getTileX() < 0) {
            positionX += scaleBacktoPosition;
        }

        if (finalNode->getTileY() < 0) {
            positionY += scaleBacktoPosition;
        }

        rot = M_PI - atan2((finalNode->getTileX() * scaleBacktoPosition + scaleBacktoPosition/2) - positionX, (finalNode->getTileY() * scaleBacktoPosition + scaleBacktoPosition/2) - positionY);
    }
    
    //delete pathfinding nodes
    while(!fringe.empty()){
        PathFindingNode *node = fringe.top();
        fringe.pop();
        delete node;
    }

    this->setRotation(rot * (180/M_PI));
    this->move(GameState::getDeltaTime()*this->speed*sin(rot), -GameState::getDeltaTime()*this->speed*cos(rot));
}

void Enemy::draw() {
    MainWindow::getInstance().draw(*(this));
}

const boost::json::object& Enemy::getMyConfigFile() {
    return GameConfig::getInstance().getJson("resources/configs/enemy.json");
}

void Enemy::loadConfigs() {
    this->speed = this->getMyConfigFile().at("speed").as_double();
    this->setTexture(*TextureFactory::getTexture(this->getMyConfigFile().at("default_texture").as_string().c_str()));
}

float Enemy::calculateHeuristic(int x1, int y1, int x2, int y2){
    int deltaY = abs(y2 - y1);
    int deltaX = abs(x2 - x1);
    return sqrt(deltaY*deltaY + deltaX*deltaX);
}

void Enemy::addNode(int x, int y, int tx, int ty, int gcost, PathFindingNode *node, std::priority_queue<PathFindingNode*, std::vector<PathFindingNode*>, decltype(&Compare)> &fringe){
    if(GameState::getMaps()->at(this->currentMap)->getTile(x, y)->isWalkable()){
        fringe.push(new PathFindingNode(
            x, 
            y,
            calculateHeuristic(x, y, tx, ty),
            gcost,
            node
        ));
    }
}