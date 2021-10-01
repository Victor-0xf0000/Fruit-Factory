#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include <Core/Scene.h>
#include <Entities/EntityTypes.h>
#include <Tiles/Tile.h>

#include <SDL2/SDL.h>


class TestScene: public Scene
{
  public:
    TestScene();
    virtual ~TestScene();

    void loadData(Game* game) override;
    void saveLevel();

    void inputHandler(struct InputHandler* inputHandler_s, const float dt) override;
    void update(const float dt) override;
    void render(SDL_Renderer* renderer) override;

  private:
    SDL_Texture* background;
    SDL_Texture* moldure;
    class Level* lev;
    class UICButton* button;
    class UIEntitySelector* uiEntitySelector;

    class TileSystem* tileSystem;

    // Block placement
    int mode;
    int rotation;
    enum EntityType blockId;
    Tile prevTile;

    EntityType blockMap[11*11];
};

#endif // TEST_SCENE_H
