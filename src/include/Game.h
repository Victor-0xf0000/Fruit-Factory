#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Core/Sprite.h>
#include <Core/EntityManager.h>
#include <Core/Clock.h>

class Game
{
  public:
    Game();
    virtual ~Game();

    void run();
    SDL_Renderer* getRenderer();

    EntityManager* getEntityManager(); 
  private:
    bool initialize();
    bool loadData();

    void inputHandler();
    void update();
    void render();

    struct WindowManager* windowManager;
    struct SceneManager* sceneManager;
    Clock* clock;
    struct InputHandler* inputHandler_s;


    bool isRunning;
};

#endif // GAME_H
