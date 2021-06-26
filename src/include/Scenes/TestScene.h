#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include <Core/Scene.h>
#include <Entities/EntityTypes.h>

#include <SDL2/SDL.h>


class TestScene: public Scene
{
public:
	TestScene();
	virtual ~TestScene();
	
	void loadData(Game* game) override;
	void saveLevel();

	void inputHandler() override;
	void update() override;
	void render(SDL_Renderer* renderer) override;

private:
	SDL_Texture* background;
	SDL_Texture* moldure;
	class Level* lev;

	int mode;
	int blockId;

	EntityType blockMap[11][11];
};

#endif // TEST_SCENE_H
