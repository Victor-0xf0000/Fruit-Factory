#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>

class Scene
{
public:
	Scene();
	virtual ~Scene();
	
	virtual void inputHandler();
	virtual void update();
	virtual void render(SDL_Renderer* renderer);
protected:

};

#endif // SCENE_H
