#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <Core/InputType.h>
#include <Core/Math/Vector2.h>

#include <SDL2/SDL.h>


struct InputController
{
	static bool getKey(const Key key);
	// NOTE: when add support to middle button, the return type of getMouse need be an enum
	static bool getMouse(const MouseButton button);
	static Vector2i getMousePosition();
};
#endif // INPUT_CONTROLLER
