#include <Game.h>
#include <Core/WindowManager.h>

Game::Game(): windowManager(nullptr)
{
	this->windowManager = new WindowManager();
	this->windowManager->title = "Fruit Factory :)\0";
	this->isRunning = true;
}

Game::~Game()
{
	this->windowManager->~WindowManager();
}

void Game::run()
{
	if (!this->initialize()) 
	{
		SDL_Log("Cannot initialize the game");
		return;
	}
	while (this->isRunning)
	{
		this->inputHandler();
		this->update();
		this->render();
	}
}

bool Game::initialize()
{
	if (!this->windowManager->initializeWindow()) return false; 
	if (!this->windowManager->initializeRenderer()) return false;
	return true;
}

void Game::inputHandler()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				this->isRunning = false;
				break;
		}
	}
	
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE])
	{
		this->isRunning = false;
	}
}

void Game::update()
{

}

void Game::render()
{
	SDL_SetRenderDrawColor(this->windowManager->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->windowManager->renderer);

	SDL_RenderPresent(this->windowManager->renderer);
}
