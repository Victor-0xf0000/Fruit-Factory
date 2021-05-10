#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include <Core/Scene.h>

#include <SDL2/SDL.h>

class TestScene: public Scene
{
public:
	TestScene();
	virtual ~TestScene();

	void inputHandler(const Uint8* state) override;
	void update() override;
	void render(SDL_Renderer* renderer) override;
private:
	int r, g, b;
};

#endif // TEST_SCENE_H
