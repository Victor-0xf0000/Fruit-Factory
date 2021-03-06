#include <UI/UIMenus/UIEntitySelector.h>
#include <Core/InputController.h>
#include <Core/Math/MathHelper.h>
#include <Core/EntityManager.h>
#include <Core/Sprite.h>
#include <Core/Renderer.h>
#include <Entities/EntityTypes.h>
#include <Game.h>

UIEntitySelector::UIEntitySelector(int x, int y, EntityType* type, Game* game): type(type)
{
  this->x = x;
  this->y = y;

  this->bsx = this->x;
  this->bsy = this->y;
  this->bh = 48;
  this->bw = 48;

  this->background = Renderer::loadSprite(game->getRenderer(), "Data/Sprites/UIMenuBackground.png");
}

UIEntitySelector::~UIEntitySelector()
{

}

void UIEntitySelector::onMouseClick(InputHandler* inputHandler_s)
{
  int x = inputHandler_s->getState().mouse.getMousePosition().x;
  int y = inputHandler_s->getState().mouse.getMousePosition().y;

  for (int i = 0; i < this->entityOptions.size(); i++)
  {
    if (isPointOnBox(x, y, this->bsx + i * this->bw, this->bsy, this->bw, this->bh))
    {
      *this->type = this->entityOptions[i];
    }
  }
}

void UIEntitySelector::update()
{

}

void UIEntitySelector::render(SDL_Renderer* renderer)
{
  Renderer::renderSingleSprite(renderer, this->background, this->x, this->y, 300, 600);
  for (int i = 0; i < this->boxSprites.size(); i++)
  {
    Renderer::renderSpriteData(renderer, &this->boxSprites[i], this->bsx + i * this->bw, this->bsy);
  }

}

void UIEntitySelector::addEntityOption(EntityType id)
{
  this->entityOptions.push_back(id);
  SpriteData sd;

  switch (id)
  {
    case EntityType::bananaBox:
      {
        sd.ssx = 0;
        sd.ssy = 0;
        sd.height = 16;
        sd.width = 16;
        sd.scale = 3;
        break;
      }
    case EntityType::inputBlock:
      {
        sd.ssx = 32;
        sd.ssy = 0;
        sd.height = 16;
        sd.width = 16;
        sd.scale = 3;
        break;
      }
    case EntityType::conveyorTile:
      {
        sd.ssx = 48;
        sd.ssy = 0;
        sd.height = 16;
        sd.width = 16;
        sd.scale = 3;
        break;
      }
  }

  this->boxSprites.push_back(sd);
}
