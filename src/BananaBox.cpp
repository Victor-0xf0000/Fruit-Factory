#include <Entities/Boxes/BananaBox.h>
#include <Core/Sprite.h>

BananaBox::BananaBox(Sprite* spr): Entity(spr)
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
    this->spr->draw(renderer);
}

void BananaBox::inputHandler()
{

}