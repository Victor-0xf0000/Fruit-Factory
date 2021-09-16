#include <UI/UIComponents/UICButton.h>
#include <Core/Renderer.h>
#include <Core/InputController.h>

#include <stdio.h>

UICButton::UICButton(int x, int y, const char* msg): UIComponent(ComponentType::button)
{
    this->msg = (char*) malloc(sizeof(char) * 50);
    this->sd = new SpriteData();
    this->sd->ssx = 80;
    this->sd->ssy = 0;
    this->sd->width = 32;
    this->sd->height = 16;
    this->sd->scale = 3;

    this->x = x;
    this->y = y;
    this->msg = (char*) msg;

    this->pressed = false;
}

UICButton::~UICButton()
{}

void UICButton::input(InputHandler* inputHandler_s)
{
    if (inputHandler_s->getState().mouse.getMouse(MouseButton::BUTTON_LEFT))
    {
        int x = inputHandler_s->getState().mouse.getMousePosition().x;
        int y = inputHandler_s->getState().mouse.getMousePosition().y;

        if (x > this->x && x < this->x + this->sd->width * this->sd->scale &&
        y > this->y && y < this->y + this->sd->height * this->sd->scale)
        {
            this->pressed = true;
        }
        
    }
    else
    {
        this->pressed = false;
    }
}

void UICButton::update()
{

}

void UICButton::render(SDL_Renderer* renderer)
{
    Renderer::renderSpriteData(renderer, this->sd, this->x, this->y);
    Renderer::drawText(renderer, this->msg, this->x, this->y);
}

bool UICButton::isPressed()
{
    return this->pressed;
}
