#ifndef STORAGE_TILE_H
#define STORAGE_TILE_H

#include <Tiles/Tile.h>
#include <Core/ErrorLog.h>

struct StorageTile: Tile
{
   StorageTile();

   void onCreate(class TileSystem* tileSystem) override;
   void onDestroy(class TileSystem* tileSystem) override;

   void 
   updateNearbyEntities(class TileSystem* tileSystem) override;   
   void nearbyUpdate(const float dt)
   {
      fLOG("Tile updated by nearbyUpdate");
   }
};

#endif // STORAGE_TILE_H
