#include <Game.h>

#include <Core/WindowManager.h>
#include <Core/SceneManager.h>
#include <Core/EntityManager.h>
#include <Core/ErrorLog.h>
#include <Core/InputController.h>
#include <Core/Renderer.h>

#include <Scenes/TestScene.h>

#include <SDL2/SDL_ttf.h>

Game::Game(): windowManager(nullptr),
  sceneManager(nullptr)
{
  this->windowManager = new WindowManager();
  this->windowManager->title = (char*) "Fruit Factory :)\0";

  this->sceneManager = new SceneManager();
  this->isRunning = true;

  this->inputHandler_s = new InputHandler();
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
    this->clock->tick();
    this->inputHandler();
    this->update();
    this->render();
  }
}

bool Game::initialize()
{
  if (!this->windowManager->initializeWindow()) return false; 
  if (!this->windowManager->initializeRenderer()) return false;

  TTF_Init();

  if (IMG_Init(IMG_INIT_PNG) == 0)
  {
    SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
    return false;
  }

  this->sceneManager->createScene("Test scene\0", new TestScene());
  this->sceneManager->selectScene("Test scene\0");

  if (!Renderer::loadSpriteSheet(this->windowManager->renderer, "./Data/Sprites/Spritesheet.png")) return false;

  this->clock = new Clock();

  this->loadData();

  if (!this->inputHandler_s->init())
  {
    printf("failed to initialize inputHandler\n");
  }

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

EntityManager* Game::getEntityManager()
{
  return this->sceneManager->getCurrent()->getEntityManager();
}

void Game::inputHandler()
{
  this->inputHandler_s->update();

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
  if (this->inputHandler_s->getState()
      .keyboard.getKeyState(SDL_SCANCODE_ESCAPE) == KEY_PRESSED)
  {
    this->isRunning = false;
  }
  
  this->sceneManager->getCurrent()->inputHandler(this->inputHandler_s,
      this->clock->delta);
}

void Game::update()
{
  this->sceneManager->getCurrent()->update(this->clock->delta);

}
void Game::render()
{
  this->sceneManager->getCurrent()->render(this->windowManager->renderer);
}
