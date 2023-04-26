#pragma once
#include "../EntityManager.hpp"

class FactoryBaseClass {
protected: 
    std::shared_ptr<EntityManager> manager;
public:
    FactoryBaseClass(const std::shared_ptr<EntityManager>& manager);
    ~FactoryBaseClass() = default;

};
