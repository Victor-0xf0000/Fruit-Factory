#include <Entities/Boxes/BananaBox.h>
#include <Core/Sprite.h>
#include <Core/Renderer.h>
#include <Core/ErrorLog.h>
#include <Game.h>


BananaBox::BananaBox(SpriteData* spr): Entity(spr)
{
    this->setX(30);
    this->setY(30);
}

BananaBox::~BananaBox()
{

}

void BananaBox::update(const float dt)
{

}

void BananaBox::render(SDL_Renderer* renderer)
{
    Renderer::render(renderer, this->spr);
}

void BananaBox::inputHandler()
{

}