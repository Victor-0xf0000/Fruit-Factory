#ifndef CONVEYOR_TILE_H
#define CONVEYOR_TILE_H

#include <Tiles/Tile.h>
#include <items/Items.h>

struct ConveyorTile : Tile
{
   static const int capacity = 2;
   
   Item items[capacity];
   
   void update(const float dt) override;
   void nearbyUpdate(const float dt, class TileSystem* tileSystem) override;
   
   Tile* next;
   int rotation;
};

#endif // CONVEYOR_TILE_H
