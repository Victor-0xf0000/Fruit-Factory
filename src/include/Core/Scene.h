#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>

#include <Core/EntityManager.h>

class Scene
{
public:
	Scene();
	virtual ~Scene();
	
	virtual void loadData(struct Game* game);

	virtual void inputHandler();
	virtual void update();
	virtual void render(SDL_Renderer* renderer);

	EntityManager* getEntityManager();

protected:
	EntityManager* entityManager;
};

#endif // SCENE_H
