#include "FactoryBaseClass.hpp"
#include "../EntityManager.hpp"
#include "../../Entities/Player.hpp"

class PlayerFactory : FactoryBaseClass {
private: 
public:
    PlayerFactory(std::shared_ptr<EntityManager> manager);
    ~PlayerFactory() = default;

    void createEntity(GameEntity::ID_TYPE id, int layer);
    GameEntity::ID_TYPE createEntity(int layer);
};
