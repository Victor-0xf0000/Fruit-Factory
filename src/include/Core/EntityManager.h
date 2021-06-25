#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <string>


class EntityManager
{
public:
    // Constructor and destructor
    EntityManager();
    virtual ~EntityManager();

    // Management functions
    void addEntity(class Entity* entity);
    void removeEntity(class Entity* entity);
    void removeAllEntities();

    // class Entity* findEntity(int id);
    
    // Get entities
    std::vector<class Entity*> getEntities();

private:
    std::vector<class Entity*>* entities;
};

#endif // ENTITY_MANAGER_H