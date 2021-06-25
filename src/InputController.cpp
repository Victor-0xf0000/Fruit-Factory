#include <Core/InputController.h>
#include <Core/ErrorLog.h>

KeyStatus InputController::getKey(const Key key)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[key])
		return KEY_PRESSED;
	else
		return KEY_RELEASED;
	
}

MouseStatus InputController::getMouse(const MouseButton button)
{
	if (SDL_GetMouseState(NULL, NULL) & button)
	{
		return BUTTON_PRESSED;
	}
	else
		return BUTTON_RELEASED;
		
}

Vector2i InputController::getMousePosition()
{
	int a = 0, b = 0;

	SDL_GetMouseState(&a, &b);
	
	return Vector2i(a, b);
}
