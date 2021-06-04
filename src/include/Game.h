#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Core/Sprite.h>

class Game
{
public:
  Game();
  virtual ~Game();

  void run();
	SDL_Renderer* getRenderer();
private:
  bool initialize();
	bool loadData();

  void inputHandler();
  void update();
  void render();

	struct WindowManager* windowManager;
	struct SceneManager* sceneManager;

	bool isRunning;
};

#endif // GAME_H
