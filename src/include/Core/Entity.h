#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <Core/Sprite.h>

class Entity
{
public:
    Entity(Sprite* spr);
    virtual ~Entity();

    virtual void render(SDL_Renderer* renderer);
    virtual void update(const float dt);
    virtual void inputHandler();

    int getX() const  {   return x;}
    int getY() const  {   return y;}
    void setX(int x) {   this->x = x;}
    void setY(int y) {   this->y = y;}
    Sprite* getSpr() const {   return spr;}
    
protected:
    Sprite* spr;
    int x, y;
};

#endif // ENTITY_H