#include "Enemy.hpp"

Enemy::Enemy(GameEntity* target, int layer) : GameEntity(layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/enemy.png"));
    loadConfigs();
    this->setPathFindingTarget(target);
    this->setOrigin(this->getLocalBounds().width/2, this->getLocalBounds().width/2);
}

Enemy::~Enemy(){

}

int Enemy::getTextureWidth(){
    return this->getTexture()->getSize().x;
}

void Enemy::update() {
    float tx = pathfindingTarget->getPosition().x;
    float ty = pathfindingTarget->getPosition().y;

    float rot = M_PI - atan2(tx - this->getPosition().x, ty - this->getPosition().y);
    
    printf("%f\n", rot);
    //printf("x: %f, y: %f\n", GameState::getDeltaTime()*this->speed*cos(rot), GameState::getDeltaTime()*this->speed*sin(rot));
    this->move(GameState::getDeltaTime()*this->speed*sin(rot), -GameState::getDeltaTime()*this->speed*cos(rot));
    this->setRotation(rot * (180/M_PI));
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