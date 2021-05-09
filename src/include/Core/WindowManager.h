#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SDL2/SDL.h>

struct WindowManager
{
	WindowManager();
	~WindowManager();
	
	bool initializeWindow();
	bool initializeRenderer();

	// Window configs
	int width;
	int height;
	char* title;
	
	// SDL things
	SDL_Renderer* renderer;
	SDL_Window* window;
};

#endif // WINDOW_MANAGER_H
