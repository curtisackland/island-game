#include <memory>
#include "../Entities/GameEntity.hpp"

class EntityManager {
private:
    std::unordered_map<GameEntity::ID_TYPE, std::unique_ptr<GameEntity>> entities;

public:
    EntityManager() = default;
    ~EntityManager() = default;

    GameEntity::ID_TYPE generateID();
    inline GameEntity * const getEntity(GameEntity::ID_TYPE id);
    inline void setEntity(GameEntity* entity);
    inline GameEntity::ID_TYPE setEntity(GameEntity::ID_TYPE id, GameEntity* entity);
};
