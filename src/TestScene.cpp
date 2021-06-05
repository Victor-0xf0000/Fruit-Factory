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
	
	SpriteData* sd = new SpriteData();
	sd->ssx = 0;
	sd->ssy = 0;
	sd->width = 16;
	sd->height = 16;
	sd->scale = 5;
	sd->x = 321;
	sd->y = 432;

	BananaBox* entity = new BananaBox(sd);

	this->entityManager->addEntity("banana\0", "global\0", entity);

	this->background = Renderer::loadSprite(game->getRenderer(), "Data/Sprites/Background.png");

	Level* lev = new Level();
	lev->loadLevel("Data/Levels/test.json");

}

void TestScene::inputHandler()
{
	this->entityManager->findEntity("banana\0", "global\0")->inputHandler();
}

void TestScene::update()
{
	this->entityManager->findEntity("banana\0", "global\0")->update(0.f);
}

void TestScene::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	Renderer::renderSingleSprite(renderer, this->background, 0, 0, 900, 600);
	this->entityManager->findEntity("banana\0", "global\0")->render(renderer);
	SDL_RenderPresent(renderer);
}
