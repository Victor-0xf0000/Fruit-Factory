#include <Core/Entity.h>
#include <Core/InputController.h>

Entity::Entity(Sprite* spr)
{
    this->spr = spr;
}

Entity::~Entity()
{

}

void Entity::render(SDL_Renderer* renderer)
{
}

void Entity::update(const float dt)
{

}

void Entity::inputHandler()
{

}