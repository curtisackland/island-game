#include "Enemy.hpp"

Enemy::Enemy(GameEntity* target, int layer) : GameEntity(layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/enemy.png"));
    this->setPathFindingTarget(target);
}

Enemy::~Enemy(){

}

int Enemy::getTextureWidth(){
    return TextureFactory::getTexture("resources/images/enemy.png")->getSize().x;
}

void Enemy::update() {
    // Do pathfinding here
}