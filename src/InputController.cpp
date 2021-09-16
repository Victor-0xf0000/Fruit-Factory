#include <Core/InputController.h>
#include <Core/ErrorLog.h>
#include <cstring>

//
// KeyboardState
//

keystate_t KeyboardState::getKeyState(SDL_Scancode key) const
{
  if (this->prevKeyState[key] != 0) 
  {
    if (this->currKeyState[key] == 0) 
    {
      return KEY_RELEASED;
    } else 
    {
      return KEY_HELD;
    }
  } else 
  {
    if (this->currKeyState[key] == 0) 
    {
      return KEY_NONE;
    } else 
    {
      return KEY_PRESSED;
    }
  }

} 

//
// MouseState
//

bool MouseState::getMouse(MouseButton button)
{
  return SDL_GetMouseState(NULL, NULL) & button;
}

Vector2i MouseState::getMousePosition()
{
  int a = 0, b = 0;

  SDL_GetMouseState(&a, &b);

  return Vector2i(a, b);
}

//
// InputHandler
//

bool InputHandler::init()
{                                                                         
  // currkeystate is the pointer to the sdl keyboard event state buffer  
  this->state.keyboard.currKeyState = SDL_GetKeyboardState(NULL);    

  // reset all previous values                                       
  memset(this->state.keyboard.prevKeyState, -1,      
      SDL_NUM_SCANCODES);                                            

  // if everything ok, it returns true 
  return true;                                                    
}

void InputHandler::update()
{
  memcpy(this->state.keyboard.prevKeyState,                             this->state.keyboard.currKeyState,
    SDL_NUM_SCANCODES);
}                                   
