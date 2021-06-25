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
	this->canPutAnotherEntity = true;
	this->saveButton = false;


	this->lev = new Level();
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
	
	this->lev->loadLevel(game, "Data/Levels/test.json");

}

void TestScene::saveLevel()
{
	this->lev->saveEntities(this, "Data/Levels/test.json");
}

void TestScene::inputHandler()
{
	if (InputController::getKey(Key::S) == KeyStatus::KEY_PRESSED && this->saveButton == false)
	{
		this->saveButton = true;
		this->saveLevel();
	}

	if (InputController::getMouse(MouseButton::BUTTON_LEFT) == MouseStatus::BUTTON_PRESSED && this->canPutAnotherEntity == true)
	{
		printf("A\n");
		SpriteData sd = SpriteData();
		sd.ssx = 0;
		sd.ssy = 0;
		sd.height = 16;
		sd.width = 16;
		sd.scale = 4;
		BananaBox* bb = new BananaBox(sd);
		bb->setX(InputController::getMousePosition().x / 100);
		bb->setY(InputController::getMousePosition().y / 100);
		this->entityManager->addEntity(bb);
		this->canPutAnotherEntity = false;
	}
	
	if (InputController::getKey(Key::C) == KeyStatus::KEY_PRESSED)
	{
		// TODO: Make the method be called at the end of C key pressed
		this->entityManager->removeAllEntities();
	}

	if (InputController::getMouse(MouseButton::BUTTON_LEFT) == MouseStatus::BUTTON_RELEASED)
	{
		this->canPutAnotherEntity = true;
	}

	for (auto i : this->entityManager->getEntities())
	{
		i->inputHandler();
	}
}

void TestScene::update()
{
	for (auto i : this->entityManager->getEntities())
	{
		i->update(0.f);
	}
}

void TestScene::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	
	Renderer::renderSingleSprite(renderer, this->background, 0, 0, 900, 600);
	for (auto i : this->entityManager->getEntities())
	{
		i->render(renderer);
	}
	SDL_RenderPresent(renderer);
}
