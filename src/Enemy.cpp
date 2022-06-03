#include "Enemy.hpp"

Enemy::Enemy(int layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/enemy.png"));
    this->setMapLayer(layer);
}

Enemy::~Enemy(){

}

int Enemy::getTextureWidth(){
    return TextureFactory::getTexture("resources/images/enemy.png")->getSize().x;
}

void Enemy::update() {

}