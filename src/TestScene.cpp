#include <Scenes/TestScene.h>

#include <Core/ErrorLog.h>
#include <Core/InputController.h>
#include <Core/Sprite.h>
#include <Core/Renderer.h>
#include <Entities/Boxes/BananaBox.h>
#include <Level/Level.h>
#include <Game.h>

#include <SDL2/SDL_image.h>

TestScene::TestScene(): Scene()
{
	this->entityManager = new EntityManager();
	this->background = nullptr;
	LOG("Hello from test scene :)");
}

TestScene::~TestScene()
{
	
}

void TestScene::loadData(Game* game)
{

	this->background = Renderer::loadSprite(game->getRenderer(), "Data/Sprites/Background.png");

	Level* lev = new Level();
	lev->loadLevel(game, "Data/Levels/test.json");

}

void TestScene::inputHandler()
{
	for (auto i : this->entityManager->getEntityGroup("global\0"))
	{
		i.second->inputHandler();
	}
}

void TestScene::update()
{
	for (auto i : this->entityManager->getEntityGroup("global\0"))
	{
		i.second->update(0.f);
	}
}

void TestScene::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	Renderer::renderSingleSprite(renderer, this->background, 0, 0, 900, 600);
	for (auto i : this->entityManager->getEntityGroup("global\0"))
	{
		i.second->render(renderer);
	}
	SDL_RenderPresent(renderer);
}
