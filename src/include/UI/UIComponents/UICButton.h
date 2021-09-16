#ifndef UICBUTTON_H
#define UICBUTTON_H

#include <UI/UIComponent.h>
#include <Core/Sprite.h>

class UICButton : public UIComponent
{
public:
    UICButton(int x, int y, const char* msg);
    virtual ~UICButton();

    void input(class InputHandler* inputHandler_s) override;
    void update() override;
    void render(SDL_Renderer* renderer) override; 

    bool isPressed();

private:
    SpriteData* sd;
    char* msg;
    bool pressed;
};

#endif // UICBUTTON_H
