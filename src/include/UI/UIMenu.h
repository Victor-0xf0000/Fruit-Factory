#ifndef UI_MENU_H
#define UI_MENU_H

#include <SDL2/SDL.h>

class UIMenu
{
public:
    UIMenu();
    virtual ~UIMenu();

    virtual void onMouseClick();
    virtual void update();
    virtual void render(SDL_Renderer* renderer);
};

#endif // UI_MENU_H