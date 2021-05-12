#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <Core/InputType.h>
#include <Core/Math/Vector2.h>

#include <SDL2/SDL.h>


struct InputController
{
	static KeyStatus getKey(const Key key);
	static MouseStatus getMouse(const MouseButton button);
	static Vector2i getMousePosition();
	
};
#endif // INPUT_CONTROLLER
