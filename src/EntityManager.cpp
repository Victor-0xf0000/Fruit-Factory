#include <Core/EntityManager.h>
#include <Core/Entity.h>
#include <Core/ErrorLog.h>
#include <algorithm>

EntityManager::EntityManager()
{
    this->entities = new std::vector<Entity*>();
}

EntityManager::~EntityManager()
{

}

// Management functions
void EntityManager::addEntity(Entity* entity)
{
    this->entities->push_back(entity);
}

void EntityManager::removeEntity(Entity* entity)
{
    auto iter = std::find(this->entities->begin(), this->entities->end(), entity);
    // Swap to end of vector and pop off (avoid erase copies)
    std::iter_swap(iter, this->entities->end() - 1);
    this->entities->pop_back();

    delete entity;
}

void EntityManager::removeAllEntities()
{
    while (!this->entities->empty())
    {
        this->entities->pop_back();
    }
}

// Get entities
std::vector<Entity*> EntityManager::getEntities()
{
    return *this->entities;
}