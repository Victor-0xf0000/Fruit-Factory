#ifndef INPUT_TYPE_H
#define INPUT_TYPE_H

#include <SDL2/SDL.h>

enum Key 
{
	A = SDLK_a, 
	B = SDLK_b,
	C = SDLK_c,
	D = SDLK_d,
	E = SDLK_e,
	F = SDLK_f,
	G = SDLK_g,
	H = SDLK_h,
	I = SDLK_i,
	J = SDLK_j,
	K = SDLK_k,
	L = SDLK_l,
	M = SDLK_m,
	N = SDLK_n,
	O = SDLK_o,
	P = SDLK_p,
	Q = SDLK_q,
	R = SDLK_r,
	S = SDLK_s,
	T = SDLK_t,
	U = SDLK_u,
	V = SDLK_v,
	W = SDLK_w,
	X = SDLK_x,
	Y = SDLK_y,
	Z = SDLK_z,
	KEY_ESCAPE = SDLK_ESCAPE
};


enum MouseButton
{
	BUTTON_RIGHT = SDL_BUTTON_RMASK,
	BUTTON_LEFT = SDL_BUTTON_LMASK,
	BUTTON_MIDDLE = SDL_BUTTON_MMASK
};

enum keystate_t
{
   KEY_NONE = -1,
   KEY_RELEASED,
   KEY_PRESSED, 
   KEY_HELD
};

#endif // INPUT_TYPE_H
