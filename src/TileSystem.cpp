#include <Tiles/TileSystem.h>
#include <Tiles/Tile.h>
#include <iostream>

TileSystem::TileSystem(int width, int height)
{
   this->width = width;
   this->height = height;

   this->tiles = std::vector<Tile*>(width * height);
   
   this->pseudoTile = new Tile();
   this->pseudoTile->sd.ssx = 0;
   this->pseudoTile->sd.ssy = 0;
   this->pseudoTile->x = 5;
   this->pseudoTile->x = 5;
   this->pseudoTile->sd.width = 0;
   this->pseudoTile->sd.height = 0;
   this->pseudoTile->sd.scale = 0;
   this->pseudoTile->type = EntityType::pseudoTile;

   for (int i = 0; i < this->tiles.size(); i++)
   {
      Tile* tile = new Tile();
      
      // create the tile

      tile->sd.ssx = 0;
      tile->sd.ssy = 0;
      tile->x = (i - this->width * (i / this->width)) * 48;
      tile->y = ((i - tile->x / 48) / this->width) * 48;
      tile->sd.width = 0;
      tile->sd.height = 0;
      tile->sd.scale = 0;
      tile->type = EntityType::air;
      
      this->tiles[i] = tile;
   }
}

TileSystem::~TileSystem()
{

}

Tile* TileSystem::getTile(int x, int y)
{
   return x < 12 && x > 0 && y < 12 && y > 0 ?
      (this->tiles[x + y * this->width])
      : this->pseudoTile;
}

Tile* TileSystem::getTile(int pos)
{
   return this->tiles[pos];

}

void TileSystem::addTile(Tile* tile, int x, int y)
{
   tile->x = x*48;
   tile->y = y*48;
   this->tiles[x + y * this->width] = tile;
}

std::vector<Tile*>* TileSystem::getTiles()
{
   return &this->tiles;
}

