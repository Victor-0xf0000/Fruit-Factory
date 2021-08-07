#include <UI/UIMenus/UIEntitySelector.h>
#include <Core/InputController.h>
#include <Core/Math/MathHelper.h>
#include <Core/EntityManager.h>
#include <Core/Sprite.h>
#include <Core/Renderer.h>
#include <Entities/EntityTypes.h>

UIEntitySelector::UIEntitySelector(int x, int y, EntityType* type): type(type)
{
    this->x = x;
    this->y = y;

    this->bsx = this->x;
    this->bsy = this->y;
    this->bh = 48;
    this->bw = 48;

}

UIEntitySelector::~UIEntitySelector()
{

}

void UIEntitySelector::onMouseClick()
{
    int x = InputController::getMousePosition().x;
    int y = InputController::getMousePosition().y;

    for (int i = 0; i < this->entityOptions.size(); i++)
    {
        if (isPointOnBox(x, y, this->bsx + i * this->bw, this->bsy, this->bw, this->bh))
        {
            *this->type = this->entityOptions[i];
            printf("bruh\n");
        }
    }
}

void UIEntitySelector::update()
{

}

void UIEntitySelector::render(SDL_Renderer* renderer)
{
    for (int i = 0; i < this->boxSprites.size(); i++)
    {
        Renderer::renderSpriteData(renderer, &this->boxSprites[i], this->bsx + i * this->bw + 10,
        this->bsy);
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
    }

    this->boxSprites.push_back(sd);
}