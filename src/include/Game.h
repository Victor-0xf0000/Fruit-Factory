#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game
{
public:
  Game();
  virtual ~Game();

  void run();
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
