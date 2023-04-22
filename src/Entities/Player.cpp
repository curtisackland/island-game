#include "Player.hpp"

Player::Player(GameEntity::ID_TYPE id, int layer) : GameEntity(id, layer){
    this->setTexture(*TextureFactory::getTexture("resources/images/player.png"));
    this->setMapLayer(0);
    this->loadConfigs();
}

void Player::releaseReferences() {
    GameEntity::releaseReferences();
}

int Player::getTextureWidth(){
    return this->getTexture()->getSize().x;
}

void Player::update() {
    this->speed = getMyConfigFile().at("speed").as_double();
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) 
    || (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
        this->speed = this->speed*this->diagonalScalar;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        int x = (int) floor((this->getPosition().x-speed*GameState::getInstance().getTiming().getDeltaTime() - this->getGlobalBounds().width/2)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int y1 = (int) floor((this->getPosition().y + this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int y2 = (int) floor((this->getPosition().y - this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());

        if((this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y1)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y1)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y2)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y2)->isWalkable())){

        }else {
            this->move(-this->speed*GameState::getInstance().getTiming().getDeltaTime(), 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        int x = (int) floor((this->getPosition().x + this->speed*GameState::getInstance().getTiming().getDeltaTime() + this->getGlobalBounds().width/2)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int y1 = (int) floor((this->getPosition().y + this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int y2 = (int) floor((this->getPosition().y - this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());

        if((this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y1)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y1)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y2)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x, y2)->isWalkable())){

        } else {
            this->move(this->speed*GameState::getInstance().getTiming().getDeltaTime(), 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        int x1 = (int) floor((this->getPosition().x + this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int x2 = (int) floor((this->getPosition().x - this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int y = (int) floor((this->getPosition().y - this->speed*GameState::getInstance().getTiming().getDeltaTime() - this->getGlobalBounds().height/2)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());

        if((this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x1, y)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x1, y)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x2, y)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x2, y)->isWalkable())){
        } else {
            this->move(0, -this->speed*GameState::getInstance().getTiming().getDeltaTime());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        int x1 = (int) floor((this->getPosition().x + this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int x2 = (int) floor((this->getPosition().x - this->getGlobalBounds().width/4)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());
        int y = (int) floor((this->getPosition().y + this->speed*GameState::getInstance().getTiming().getDeltaTime() + this->getGlobalBounds().height/2)/GameState::getInstance().getMainView()->getSize().x * GameConfig::getInstance().getJson("resources/configs/const-settings.json").at("map").at("tiles-per-window-width").as_double());

        if((this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x1, y)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x1, y)->isWalkable())
            || (this->getGlobalBounds().intersects(GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x2, y)->getGlobalBounds()) 
            && !GameState::getInstance().getMaps()->at(this->getMapLayer())->getTile(x2, y)->isWalkable())){
        } else {
            this->move(0, this->speed*GameState::getInstance().getTiming().getDeltaTime());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        GameConfig::getInstance().forceRead();
    }
    this->setRotation(180 - atan2(sf::Mouse::getPosition(*GameState::getInstance().getMainWindow()).x - (float) GameState::getInstance().getMainWindow()->getSize().x/2, sf::Mouse::getPosition(*GameState::getInstance().getMainWindow()).y - (float) GameState::getInstance().getMainWindow()->getSize().y/2) * (180/M_PI));
}

void Player::draw() {
    GameState::getInstance().getMainWindow()->draw(*this);
}

const boost::json::object& Player::getMyConfigFile() {
    return GameConfig::getInstance().getJson("resources/configs/player.json");
}

void Player::loadConfigs() {
    this->setTexture(*TextureFactory::getTexture(this->getMyConfigFile().at("default_texture").as_string().c_str()));
}
