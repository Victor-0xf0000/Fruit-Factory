#include <Core/EntityManager.h>
#include <Core/Entity.h>
#include <Core/ErrorLog.h>

EntityManager::EntityManager()
{
    this->entityGroups = new std::unordered_map<std::string, entityGroup*>();

    // global is the default group
    this->createGroup("global\0");
}

EntityManager::~EntityManager()
{

}

// Management functions
void EntityManager::addEntity(const char* id, const char* group, Entity* entity)
{
    this->entityGroups->at(group)->insert(std::unordered_map<std::string, Entity*>::value_type(id, entity));
}

void EntityManager::removeEntity(const char* id, const char* group)
{
    this->entityGroups->at(group)->erase(id);
}

void EntityManager::createGroup(const char* name)
{
    this->entityGroups->insert(std::unordered_map<std::string, entityGroup*>::value_type(name, new std::unordered_map<std::string, Entity*>));
}

Entity* EntityManager::findEntity(const char* id, const char* group)
{
    return this->entityGroups->at(group)->at(id);
}

// Get entities
std::unordered_map<std::string, Entity*> EntityManager::getEntityGroup(const char* group)
{
    return *this->entityGroups->at(group);
}