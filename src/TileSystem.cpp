#include <Tiles/TileSystem.h>
#include <Tiles/Tile.h>

TileSystem::TileSystem(int width, int height)
{
   this->width = width;
   this->height = height;

   this->tiles = std::vector<Tile*>(width * height);
   
   for (int i = 0; i < this->tiles.size(); i++)
   {
      Tile* tile = new Tile();
      tile->sd.ssx = 0;
      tile->sd.ssy = 0;
      tile->x = 0;
      tile->y = 0;
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
   return this->tiles[x + y * this->width];
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

