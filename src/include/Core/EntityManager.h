#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <unordered_map>
#include <string>

typedef std::unordered_map<std::string, class Entity*> entityGroup;


class EntityManager
{
public:
    // Constructor and destructor
    EntityManager();
    virtual ~EntityManager();

    // Management functions
    void addEntity(const char* id, const char* group, class Entity* entity);
    void removeEntity(const char* id, const char* group);
    void createGroup(const char* name);

    class Entity* findEntity(const char* id, const char* group);

    
    // Get entities
    std::unordered_map<std::string, class Entity*> getEntityGroup(const char* group);

private:
    std::unordered_map<std::string, entityGroup*>* entityGroups;
};

#endif // ENTITY_MANAGER_H