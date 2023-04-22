#include "FactoryBaseClass.hpp"

FactoryBaseClass::FactoryBaseClass(const std::shared_ptr<EntityManager>& manager) {
    this->manager = manager;
}
