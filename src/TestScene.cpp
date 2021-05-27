#include <Scenes/TestScene.h>

#include <Core/ErrorLog.h>
#include <Core/InputController.h>
#include <Core/Sprite.h>
#include <Entities/Boxes/BananaBox.h>
#include <Game.h>

#include <SDL2/SDL_image.h>

TestScene::TestScene(): Scene()
{
	this->entityManager = new EntityManager();
	this->changeBackground = 0b00;
	this->r = 9;
	this->g = 4; 
	this->b = 12;
	LOG("Hello from test scene :)");
}

TestScene::~TestScene()
{
}

void TestScene::loadData(Game* game)
{
	Sprite* sp;
	BananaBox* entity;

	sp = new Sprite();
	
	SpriteData* sd = new SpriteData();

	sp->setSize(16, 16);
	sp->setPosition(100, 106);
	sp->setScale(5);
		
	SDL_Texture* texture = IMG_LoadTexture(game->getRenderer(), "./Data/Sprites/TestSprite.png");
	sd->texture = texture;
	sd->rect = NULL;
	
	sp->setSpriteData(sd);

	entity = new BananaBox(sp);

	this->entityManager->addEntity("banana\0", "global\0", entity);

}

void TestScene::inputHandler()
{
	if (InputController::getKey(Key::A) == KEY_PRESSED)
	{
		this->changeBackground = 0b01;		
	}
	else
	{
		if (this->changeBackground == 0b01)
		{
			if (this->r == 10 && this->g == 90 && this->b == 123)
			{
				this->r = 90;
				this->g = 120;
				this->b = 143;
			}
			else 
			{
				this->r = 10;
				this->g = 90;
				this->b = 123;
			}

			this->changeBackground = 0b00;
		}
	}
	//this->entity->inputHandler();
	
}

void TestScene::update()
{
	//this->entity->update(0.f);
}

void TestScene::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, this->r, this->g, this->b, 255);
	SDL_RenderClear(renderer);
	
	this->entityManager->findEntity("banana\0", "global\0")->render(renderer);
	SDL_RenderPresent(renderer);
}
