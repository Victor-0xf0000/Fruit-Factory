#ifndef INPUT_TYPE_H
#define INPUT_TYPE_H

#include <SDL2/SDL.h>

enum Key 
{
	A = SDL_SCANCODE_A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	KEY_0 = SDL_SCANCODE_0,
	KEY_1 = SDL_SCANCODE_1,
	KEY_2 = SDL_SCANCODE_2,
	KEY_3 = SDL_SCANCODE_3,
	KEY_4 = SDL_SCANCODE_4,
	KEY_5 = SDL_SCANCODE_5,
	KEY_6 = SDL_SCANCODE_6,
	KEY_7 = SDL_SCANCODE_7,
	KEY_8 = SDL_SCANCODE_8,
	KEY_9 = SDL_SCANCODE_9,
	KEY_ESCAPE = SDL_SCANCODE_ESCAPE
};


enum MouseButton
{
	BUTTON_RIGHT = SDL_BUTTON_RMASK,
	BUTTON_LEFT = SDL_BUTTON_LMASK,
	BUTTON_MIDDLE = SDL_BUTTON_MMASK
};

#endif // INPUT_TYPE_H
