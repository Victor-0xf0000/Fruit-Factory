#include <Core/WindowManager.h>
#include <stdlib.h>

WindowManager::WindowManager(): renderer(nullptr), window(nullptr)
{
	this->width = 0;
	this->height = 0;
	this->title = (char*) malloc(sizeof(char) * 30);
}

WindowManager::~WindowManager()
{
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
}

bool WindowManager::initializeWindow()
{
	if (this->width == 0)
	{
		this->width = 900;
	}
	
	if (this->height == 0)
	{
		this->height = 600;
	}

	this->window = SDL_CreateWindow(this->title, // title
			100, // position
			100,
			this->width, // size
			this->height,
			0 // flags, 0 for no set
			);
	if (!this->window)
	{
		SDL_Log("Unable to create window: %s", SDL_GetError());
		return false;
	}
	return true;
}

bool WindowManager::initializeRenderer()
{
	if (!this->window)
	{
		SDL_Log("No window set to renderer");
		return false;
	}
	
	this->renderer = SDL_CreateRenderer(this->window, // Window to render for
			-1, // Usually -1
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC // Flags
			);

	if (!this->renderer)
	{
		SDL_Log("Unable to create renderer: %s", SDL_GetError());
		return false;
	}
	return true;
}


