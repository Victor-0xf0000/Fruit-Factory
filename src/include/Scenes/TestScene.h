#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include <Core/Scene.h>

#include <SDL2/SDL.h>


class TestScene: public Scene
{
public:
	TestScene();
	virtual ~TestScene();
	
	void loadData(Game* game) override;

	void inputHandler() override;
	void update() override;
	void render(SDL_Renderer* renderer) override;

private:
	SDL_Texture* background;
};

#endif // TEST_SCENE_H
