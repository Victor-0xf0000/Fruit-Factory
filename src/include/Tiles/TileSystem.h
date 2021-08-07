#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <vector>

class TileSystem
{
public:
   TileSystem(int width, int height);
   virtual ~TileSystem();

   struct Tile* getTile(int x, int y);
   struct Tile* getTile(int pos);
   
   void addTile(Tile* tile, int x, int y);

   std::vector<struct Tile*>* getTiles();
	int getWidth() const
	{ return this->width;}
	int getHeight() const
	{ return this->height;}
private:
   std::vector<struct Tile*> tiles;
   int width, height;
};

#endif // TILE_MAP_H
