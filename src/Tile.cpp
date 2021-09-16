#include <Tiles/Tile.h>
#include <Tiles/TileSystem.h> 

void Tile::update(const float dt){}

void Tile::nearbyUpdate(const float dt, TileSystem* tileSystem)
{
}

void Tile::onCreate(TileSystem* tileSystem)
{
   this->updateNearbyEntities(tileSystem);
}
void Tile::onDestroy(TileSystem* tileSystem)
{
   this->updateNearbyEntities(tileSystem);
}

//
// Update all adjacent entities
//

void 
Tile::updateNearbyEntities(TileSystem* tileSystem)
{
   // put it on grid scale
   int x = this->x / 48;
   int y = this->y / 48;
   
   tileSystem->getTile(x-1,  y)->nearbyUpdate(0.f, tileSystem);
   tileSystem->getTile(x+1,  y)->nearbyUpdate(0.f, tileSystem);
   tileSystem->getTile(x-1,y-1)->nearbyUpdate(0.f, tileSystem);
   tileSystem->getTile(x+1,y+1)->nearbyUpdate(0.f, tileSystem);
   tileSystem->getTile(x,  y-1)->nearbyUpdate(0.f, tileSystem);
   tileSystem->getTile(x,  y+1)->nearbyUpdate(0.f, tileSystem);
   tileSystem->getTile(x+1,y-1)->nearbyUpdate(0.f, tileSystem);
   tileSystem->getTile(x-1,y-1)->nearbyUpdate(0.f, tileSystem);
}

