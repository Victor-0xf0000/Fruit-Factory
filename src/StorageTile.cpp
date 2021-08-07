#include <Tiles/logic/Storage/StorageTile.h>
#include <Tiles/TileSystem.h>

StorageTile::StorageTile()
{

}

void StorageTile::onCreate(TileSystem* tileSystem)
{
   this->updateNearbyEntities(tileSystem);
}

void StorageTile::onDestroy(TileSystem* tileSystem)
{
   this->updateNearbyEntities(tileSystem);
}

void StorageTile::updateNearbyEntities(TileSystem* tileSystem)
{
   tileSystem->getTile(this->x-1,  this->y)->nearbyUpdate(0.f);
   tileSystem->getTile(this->x+1,  this->y)->nearbyUpdate(0.f);
   tileSystem->getTile(this->x-1,this->y-1)->nearbyUpdate(0.f);
   tileSystem->getTile(this->x+1,this->y+1)->nearbyUpdate(0.f);
   tileSystem->getTile(this->x,  this->y-1)->nearbyUpdate(0.f);
   tileSystem->getTile(this->x,  this->y+1)->nearbyUpdate(0.f);
   tileSystem->getTile(this->x+1,this->y-1)->nearbyUpdate(0.f);
   tileSystem->getTile(this->x-1,this->y-1)->nearbyUpdate(0.f);
}
