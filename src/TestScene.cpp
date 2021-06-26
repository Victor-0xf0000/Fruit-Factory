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
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			this->blockMap[i][j] = EntityType::air;
		}
	}



	this->lev = new Level();
	this->entityManager = new EntityManager();

	this->background = nullptr;
	this->moldure = nullptr;

	this->mode = 1; // block place
	this->blockId = EntityType::bananaBox;

	LOG("Hello from test scene :)");
}

TestScene::~TestScene()
{
}

void TestScene::loadData(Game* game)
{

	this->background = Renderer::loadSprite(game->getRenderer(), "Data/Sprites/Background.png");
	this->moldure = Renderer::loadSprite(game->getRenderer(), "Data/Sprites/Moldure.png");

	this->lev->loadLevel(game, "Data/Levels/test.json");

}

void TestScene::saveLevel()
{
	this->lev->saveEntities(this, "Data/Levels/test.json");
}

void TestScene::inputHandler()
{
	if (InputController::getKey(Key::S) == KeyStatus::KEY_PRESSED)
	{
		this->saveLevel();
	}

	if (this->mode == 1)
	{
		if (InputController::getMouse(MouseButton::BUTTON_LEFT) == MouseStatus::BUTTON_PRESSED)
		{
			switch (this->blockId)
			{
				case EntityType::bananaBox:
				{
					int arrayX = (int) InputController::getMousePosition().x / 48;
					int arrayY = (int) InputController::getMousePosition().y / 48;

					if (InputController::getMousePosition().y < 600 && 
					InputController::getMousePosition().x < 552 &&
					(this->blockMap[arrayX][arrayY] != EntityType::bananaBox))
					{
						this->blockMap[arrayX][arrayY] = EntityType::bananaBox;

						SpriteData sd = SpriteData();
						sd.ssx = 0;
						sd.ssy = 0;
						sd.height = 16;
						sd.width = 16;
						sd.scale = 3;
						BananaBox* bb = new BananaBox(sd);
						bb->setX(InputController::getMousePosition().x);
						bb->setY(InputController::getMousePosition().y);
						this->entityManager->addEntity(bb);
					}
				}
			}
		}
	}

	else if (this->mode == 2)
	{
		if (InputController::getMouse(MouseButton::BUTTON_LEFT) == MouseStatus::BUTTON_PRESSED)
		{
			int x = InputController::getMousePosition().x;
			int y = InputController::getMousePosition().y;
			int arrayX = (int) x / 48;
			int arrayY = (int) y / 48;

			this->blockMap[arrayX][arrayY] = EntityType::air;

			for (auto entity : this->entityManager->getEntities())
			{
				if ((x >= entity->getX() && x <= (entity->getX() + entity->getSpr().width * entity->getSpr().scale)) &&
				(y >= entity->getY() && y <= (entity->getY() + entity->getSpr().height * entity->getSpr().scale)))
				{
					this->entityManager->removeEntity(entity);
					break;
				}
			}
		}
	}
	
	if (InputController::getKey(Key::C) == KeyStatus::KEY_PRESSED)
	{
		// TODO: Make the method be called at the end of C key pressed
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				this->blockMap[i][j] = EntityType::air;
			}
		}
		this->entityManager->removeAllEntities();
	}

	if (InputController::getKey(Key::P) == KeyStatus::KEY_PRESSED)
	{
		this->mode = 1;
	}

	else if (InputController::getKey(Key::D) == KeyStatus::KEY_PRESSED)
	{
		this->mode = 2;
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

	Renderer::renderSingleSprite(renderer, this->moldure, 0, 0, 600, 600);
	SDL_RenderPresent(renderer);
}
