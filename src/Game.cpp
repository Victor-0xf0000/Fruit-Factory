#include <Game.h>

#include <Core/WindowManager.h>
#include <Core/SceneManager.h>
#include <Core/ErrorLog.h>

#include <Scenes/TestScene.h>

Game::Game(): windowManager(nullptr),
	sceneManager(nullptr)
{
	this->windowManager = new WindowManager();
	this->windowManager->title = "Fruit Factory :)\0";

	this->sceneManager = new SceneManager();
	this->isRunning = true;
}

Game::~Game()
{
	this->windowManager->~WindowManager();
	this->sceneManager->~SceneManager();
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
	
	this->sceneManager->createScene("Test scene\0", new TestScene());
	this->sceneManager->selectScene("Test scene\0");
	return true;
}

bool Game::loadData()
{
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

	this->sceneManager->getCurrent()->inputHandler(state);
	
}

void Game::update()
{

}

void Game::render()
{
	this->sceneManager->getCurrent()->render(this->windowManager->renderer);

}
