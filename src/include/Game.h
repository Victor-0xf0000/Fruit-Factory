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

  void inputHandler();
  void update();
  void render();

	struct WindowManager* windowManager;
	bool isRunning;
};

#endif // GAME_H
