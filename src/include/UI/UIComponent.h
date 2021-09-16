#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include <SDL2/SDL.h>

enum ComponentType
{
    button
};

class UIComponent
{
public:
    UIComponent(ComponentType type);
    virtual ~UIComponent();
    
    virtual void input(class InputHandler* inputHandler_s);
    virtual void update();
    virtual void render(SDL_Renderer* renderer);
protected:
    ComponentType type;
    int x;
    int y;
};

#endif // UICOMPONENT_H
