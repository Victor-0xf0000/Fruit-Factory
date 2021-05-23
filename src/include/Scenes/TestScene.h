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
	int r, g, b;
	int changeBackground;
	class Sprite* sp;
	class BananaBox* entity;
};

#endif // TEST_SCENE_H
