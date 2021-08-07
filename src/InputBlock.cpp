#include <Entities/Blocks/InputBlock.h>
#include <Core/Sprite.h>
#include <Core/Renderer.h>

InputBlock::InputBlock(SpriteData spr): Entity(spr)
{
    this->type = EntityType::inputBlock;
    this->setX(30);
    this->setY(30);
}

InputBlock::~InputBlock()
{

}

void InputBlock::update(const float dt)
{

}

void InputBlock::inputHandler()
{

}

void InputBlock::render(SDL_Renderer* renderer)
{
    Renderer::renderSingleEntity(renderer, this);
}