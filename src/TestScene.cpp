#include <Scenes/TestScene.h>

#include <Core/ErrorLog.h>
#include <Core/InputController.h>
#include <Core/Sprite.h>
#include <Core/Renderer.h>
#include <UI/UIComponents/UICButton.h>
#include <UI/UIMenus/UIEntitySelector.h>
#include <Entities/Boxes/BananaBox.h>
#include <Entities/Blocks/InputBlock.h>
#include <Level/Level.h>
#include <Tiles/TileSystem.h>
#include <Tiles/Tile.h>
#include <Game.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

TestScene::TestScene(): Scene()
{
  for (int x = 0; x < 11; x++)
  {
    for (int y = 0; y < 11; y++)
    {
      this->blockMap[x + 11 * y] = EntityType::air;
    }
  }


  this->lev = new Level();
  this->entityManager = new EntityManager();

  this->uiEntitySelector = new UIEntitySelector(600, 0, &this->blockId);

  this->tileSystem = new TileSystem(12, 12);

  this->background = nullptr;
  this->moldure = nullptr;

  this->mode = 1; // block place
  this->rotation = 0;
  this->blockId = EntityType::air;

  fLOG("Hello from test scene :)");
}

TestScene::~TestScene()
{
}

void TestScene::loadData(Game* game)
{
  Renderer::loadFont("Data/ARIAL.TTF");

  this->background = Renderer::loadSprite(game->getRenderer(), "Data/Sprites/Background.png");
  this->moldure = Renderer::loadSprite(game->getRenderer(), "Data/Sprites/Moldure.png");

  this->lev->loadLevel(game, "Data/Levels/test.json");
  // this->lev->loadBlockmap(&this->blockMap, "Data/Levels/test.json");

  this->uiEntitySelector->addEntityOption(EntityType::bananaBox);
  this->uiEntitySelector->addEntityOption(EntityType::inputBlock);
  this->uiEntitySelector->addEntityOption(EntityType::conveyorTile);

  this->button = new UICButton(600, 0, "Save");	
}

void TestScene::saveLevel()
{
  this->lev->saveEntities(this, "Data/Levels/test.json");
  // this->lev->saveBlockmap(&(this->blockMap), "Data/Levels/test.json");
}

void TestScene::inputHandler(InputHandler* inputHandler_s, const float dt)
{
  // To place tile 
  if (inputHandler_s->getState().mouse.getMouse(MouseButton::BUTTON_LEFT))
  {
    // Calls the uitEntitySelector mouse callback
    // TODO: make a mousePressed, mouseNone, mouseReleased and mouseHeld
    this->uiEntitySelector->onMouseClick(inputHandler_s);

    // Is the mouse position square on the square grid?
    if ((inputHandler_s->getState().mouse.getMousePosition().x / 48 <
          this->tileSystem->getWidth()) &&
        inputHandler_s->getState().mouse.getMousePosition().y / 48 <
        this->tileSystem->getHeight())
    {
      Tile* tile = new Tile();
      SpriteData sd;

      EntityType type = this->uiEntitySelector->getEntityType();

      // Texture for undefined
      sd.ssx = 112;
      sd.ssy = 0;

      switch (type)
      {
        case EntityType::bananaBox:
          {
            sd.ssx = 48;
            break;
          }
        case EntityType::inputBlock:
          {
            sd.ssx = 32;
            break;
          }
        case EntityType::conveyorTile:
          {
            sd.ssx = 48;
            switch (this->rotation)
            {
              case 0:
              sd.ssy = 0;
              break;

              case 1:
              sd.ssy = 16;
              break;

              case 2:
              sd.ssy = 32;
              break;

              case 3:
              sd.ssy = 48;
              break;
            }

            break;
          }
      }

      sd.width = 16;
      sd.height = 16;
      sd.scale = 3;
      tile->sd = sd;
      tile->type = type;
      tile->x = inputHandler_s->getState().mouse.getMousePosition().x / 48;
      tile->y = inputHandler_s->getState().mouse.getMousePosition().y / 48;

      this->tileSystem->addTile(tile, 
          inputHandler_s->getState().mouse.getMousePosition().x / 48,
          inputHandler_s->getState().mouse.getMousePosition().y / 48);  
      tile->onCreate(this->tileSystem);
    }
  }

  // To destroy tile 
  if (inputHandler_s->getState().mouse.getMouse(MouseButton::BUTTON_RIGHT))
  {
    // Is the mouse position square on the square grid?
    if ((inputHandler_s->getState().mouse.getMousePosition().x / 48 <
          this->tileSystem->getWidth()) &&
        inputHandler_s->getState().mouse.getMousePosition().y / 48 <
        this->tileSystem->getHeight())
    {
      this->tileSystem->getTile(
        inputHandler_s->getState().mouse.getMousePosition().x / 48,
        inputHandler_s->getState().mouse.getMousePosition().y / 48)->
        onDestroy(this->tileSystem);

      Tile* tile = new Tile();
      SpriteData sd;
      sd.ssx = 0;
      sd.ssy = 0;

      sd.scale = 0;
      sd.width = 0;
      sd.height = 0;
      tile->sd = sd;
      tile->type = EntityType::air;
      this->tileSystem->addTile(tile,
          inputHandler_s->getState().mouse.getMousePosition().x / 48,
          inputHandler_s->getState().mouse.getMousePosition().y / 48);
    }

  }

  if (inputHandler_s->getState().keyboard.getKeyState(SDL_SCANCODE_R)
      == KEY_PRESSED)
  {
    this->rotation++;
    if (this->rotation == 4) this->rotation = 0;
  }

  for (auto i : this->entityManager->getEntities())
  {
    i->inputHandler();
  }
}

void TestScene::update(const float dt)
{
  this->uiEntitySelector->update();
  for (auto i : this->entityManager->getEntities())
  {
    i->update(0.f);
  }

  // printf("DT: %f\n", dt);
}

void TestScene::render(SDL_Renderer* renderer)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  Renderer::renderSingleSprite(renderer, this->background, 0, 0, 900, 600);

  for (auto i : this->entityManager->getEntities())
  {
    i->render(renderer);
  }

  for (auto i : *this->tileSystem->getTiles())
  {
    if (!i->type == EntityType::air)
      Renderer::renderSpriteData(renderer, &i->sd, i->x, i->y);
  } 

  Renderer::renderSingleSprite(renderer, this->moldure, 0, 0, 600, 600);
  // this->button->render(renderer);
  this->uiEntitySelector->render(renderer);
  SDL_RenderPresent(renderer);
}
