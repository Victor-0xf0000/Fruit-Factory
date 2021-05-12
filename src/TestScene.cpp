#include <Scenes/TestScene.h>

#include <Core/ErrorLog.h>
#include <Core/InputController.h>

#include <SDL2/SDL.h>

TestScene::TestScene(): Scene()
{
	this->changeBackground = 0b00;
	this->r = 9;
	this->g = 4; 
	this->b = 12;
	LOG("Hello from test scene :)");
}

TestScene::~TestScene()
{
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
	
}

void TestScene::update()
{

}

void TestScene::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, this->r, this->g, this->b, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}
