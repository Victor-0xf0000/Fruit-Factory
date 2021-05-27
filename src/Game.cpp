#include <Game.h>

#include <Core/WindowManager.h>
#include <Core/SceneManager.h>
#include <Core/ErrorLog.h>
#include <Core/InputController.h>

#include <Scenes/TestScene.h>

Game::Game(): windowManager(nullptr),
	sceneManager(nullptr)
{
	this->windowManager = new WindowManager();
	this->windowManager->title = "Fruit Factory :)\0";

	this->sceneManager = new SceneManager();
	this->isRunning = true;

	this->sp = new Sprite();
	
	SpriteData* sd = new SpriteData();
	
	SDL_Surface* surf = IMG_Load("Data/Sprites/TestSprite.png");

	sd->texture = SDL_CreateTextureFromSurface(this->windowManager->renderer, surf);
	SDL_FreeSurface(surf);

	this->sp->setSpriteData(sd);
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
	
	
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	this->sceneManager->createScene("Test scene\0", new TestScene());
	this->sceneManager->selectScene("Test scene\0");


	this->loadData();
	return true;
}

bool Game::loadData()
{
	this->sceneManager->getCurrent()->loadData(this);
	return true;
}

SDL_Renderer* Game::getRenderer()
{
	return this->windowManager->renderer;
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
	
	if (InputController::getKey(Key::KEY_ESCAPE) == KEY_PRESSED)
	{
		this->isRunning = false;
	}
	
	this->sceneManager->getCurrent()->inputHandler();
}

void Game::update()
{

}

void Game::render()
{
	this->sceneManager->getCurrent()->render(this->windowManager->renderer);
	

}
