#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <Core/Sprite.h>

class Entity
{
public:
    Entity(SpriteData* spr);
    virtual ~Entity();

    virtual void render(SDL_Renderer* renderer);
    virtual void update(const float dt);
    virtual void inputHandler();

    virtual int getX() const  {   return x;}
    virtual int getY() const  {   return y;}
    virtual void setX(int x) {   this->x = x;}
    virtual void setY(int y) {   this->y = y;}
    virtual SpriteData* getSpr() const {   return spr;}
    
protected:
    SpriteData* spr;
    int x, y;
};

#endif // ENTITY_H