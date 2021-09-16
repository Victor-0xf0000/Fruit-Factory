#include <UI/UIComponent.h>

UIComponent::UIComponent(ComponentType type)
{
    this->type = type;
}

UIComponent::~UIComponent()
{}

void UIComponent::input(class InputHandler* inputHandler_s)
{}

void UIComponent::update()
{}

void UIComponent::render(SDL_Renderer* renderer)
{}
