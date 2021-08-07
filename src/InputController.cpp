#include <Core/InputController.h>
#include <Core/ErrorLog.h>

bool InputController::getKey(const Key key)
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	return state[key];
}

bool InputController::getMouse(const MouseButton button)
{
	return SDL_GetMouseState(NULL, NULL) & button;
}

Vector2i InputController::getMousePosition()
{
	int a = 0, b = 0;

	SDL_GetMouseState(&a, &b);
	
	return Vector2i(a, b);
}
