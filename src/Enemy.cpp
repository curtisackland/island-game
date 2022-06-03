#include "Enemy.hpp"

Enemy::Enemy(GameEntity* target, std::vector<GameMap*>* maps, int layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/enemy.png"));
    this->setPathFindingTarget(target);
    this->maps = maps;
    this->setMapLayer(layer);
}

Enemy::~Enemy(){

}

int Enemy::getTextureWidth(){
    return TextureFactory::getTexture("resources/images/enemy.png")->getSize().x;
}

void Enemy::update() {
    // Do pathfinding here
}