#include <Scenes/TestScene.h>

#include <Core/ErrorLog.h>

#include <SDL2/SDL.h>

TestScene::TestScene(): Scene()
{
	this->r = 9;
	this->g = 4; 
	this->b = 12;
	LOG("Hello from test scene :)");
}

TestScene::~TestScene()
{
}

void TestScene::inputHandler(const Uint8* state)
{
	if (state[SDL_SCANCODE_SPACE])
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
