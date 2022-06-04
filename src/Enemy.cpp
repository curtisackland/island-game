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

void Enemy::update() {
    // Do pathfinding here
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