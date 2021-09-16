#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <Core/InputType.h>
#include <Core/Math/Vector2.h>

#include <SDL2/SDL.h>

class KeyboardState
{
public:
   // InputHandler now can access private members of KeyboardState
   friend class InputHandler;
   keystate_t getKeyState(SDL_Scancode key) const;

private:
   const uint8_t* currKeyState;
   uint8_t prevKeyState[SDL_NUM_SCANCODES];
};

class MouseState
{
public:
   // InputHandler now can access private members of MouseState
   friend class InputHandler;

   Vector2i getMousePosition();
   bool getMouse(MouseButton button);
};

struct InputState
{
   KeyboardState keyboard;
   MouseState mouse;
};

class InputHandler
{
public:
   // calls it once at the init of first update
   bool init();
   
   void update();

   InputState getState() const { return this->state;}
private:
   InputState state;
};

#endif // INPUT_CONTROLLER
