#ifndef TILE_H
#define TILE_H

#include <Core/Sprite.h>
#include <Entities/EntityTypes.h>
#include <stdio.h>

struct Tile
{
   int x, y;
   SpriteData sd;
   EntityType type;
   
   virtual void update(const float dt);
   virtual void nearbyUpdate(const float dt, class TileSystem* tileSystem);

   virtual void onCreate(class TileSystem* tileSystem);
   
   virtual void onDestroy(class TileSystem* tileSystem);

   //
   // Update all adjacent entities
   //
   virtual void 
   updateNearbyEntities(class TileSystem* tileSystem);
};

#endif // TILE_H
