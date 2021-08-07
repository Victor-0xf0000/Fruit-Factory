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

	this->button = new UICButton(600, 0, "Save");	
}

void TestScene::saveLevel()
{
	this->lev->saveEntities(this, "Data/Levels/test.json");
	// this->lev->saveBlockmap(&(this->blockMap), "Data/Levels/test.json");
}

void TestScene::inputHandler()
{
	if (InputController::getMouse(MouseButton::BUTTON_LEFT))
	{
		this->uiEntitySelector->onMouseClick();
      
      // Is the mouse position square on the square grid?
      if ((InputController::getMousePosition().x / 48 <
            this->tileSystem->getWidth()) &&
         InputController::getMousePosition().y / 48 <
            this->tileSystem->getHeight())
      {
         Tile* tile = new Tile();
         SpriteData sd;
         
         EntityType type = this->uiEntitySelector->getEntityType();
         
         // Texture for undefined
         sd.ssx = 112;
         sd.ssy = 0;

         if (type == EntityType::bananaBox)
         {
            sd.ssx = 0;
            sd.ssy = 0;
         }
         else if (type == EntityType::inputBlock)
         {
            sd.ssx = 32;
            sd.ssy = 0;
         }

         sd.width = 16;
         sd.height = 16;
         sd.scale = 3;
         tile->sd = sd;
         tile->type = type;
         this->tileSystem->addTile(tile, 
               InputController::getMousePosition().x / 48,
               InputController::getMousePosition().y / 48);  
         tile->onCreate(this->tileSystem);
      }
   }

   if (InputController::getMouse(MouseButton::BUTTON_RIGHT))
   {
      // Is the mouse position square on the square grid?
      if ((InputController::getMousePosition().x / 48 <
            this->tileSystem->getWidth()) &&
         InputController::getMousePosition().y / 48 <
            this->tileSystem->getHeight())
      {
         this->tileSystem->getTile(
               InputController::getMousePosition().x / 48,
               InputController::getMousePosition().y / 48)->onDestroy(this->tileSystem);
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
               InputController::getMousePosition().x / 48,
               InputController::getMousePosition().y / 48);
      }
      
   }
	for (auto i : this->entityManager->getEntities())
	{
		i->inputHandler();
	}
}

void TestScene::update()
{
	this->uiEntitySelector->update();
	for (auto i : this->entityManager->getEntities())
	{
		i->update(0.f);
	}
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
