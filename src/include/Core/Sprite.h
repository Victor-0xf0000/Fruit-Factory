#ifndef SPRITE_H
#define SPRITE_H

#include <Core/Math/Vector2.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct SpriteData
{
	SDL_Texture* texture;
	SDL_Rect* rect;
};

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();
	
	void setSpriteData(SpriteData* sd);
	SpriteData* getSpriteData();

	void setPosition(int x, int y);
	void setPosition(Vector2i pos);
	int getX();
	int getY();
	
	void setSize(int width, int height);
	int getWidth();
	int getHeight();
	
	void setScale(int scale);

	Vector2i getPosition();

	void draw(SDL_Renderer* renderer);
private:
	int x;
	int y;

	int width;
	int height;
	int scale;
	// TODO: add draw order!
	
	SpriteData* spriteData;
};

#endif // SPRITE_H
