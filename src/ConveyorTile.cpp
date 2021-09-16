#include <Tiles/logic/ConveyorTile.h>
#include <Tiles/TileSystem.h>

void ConveyorTile::nearbyUpdate(const float dt, TileSystem* tileSystem)
{
   // get the x and y in the front of conveyor
   int x = this->x + (this->rotation==0 ? 1 : this->rotation==2 ? -1 : 0);
   int y = this->y + (this->rotation==1 ? 1 : this->rotation==3 ? -1 : 0);
   
   // get the build at the front of the conveyor
   this->next = tileSystem->getTile(x / 48, y / 48);
   printf("type: %i\n", this->next->type);
}

void ConveyorTile::update(const float dt)
{
   
}


