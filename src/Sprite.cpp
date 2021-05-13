#include <Core/Sprite.h>
#include <stdlib.h>
#include <Core/ErrorLog.h>

Sprite::Sprite()
	: spriteData(nullptr)
{
	this->spriteData = (SpriteData*) malloc(sizeof(SpriteData));
	this->width = 0;
	this->height = 0;
	this->x = 0;
	this->y = 0;
	this->scale = 1;
}

Sprite::~Sprite()
{
	free(this->spriteData);
}

void Sprite::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Sprite::setPosition(Vector2i pos)
{
	this->x = pos.x;
	this->y = pos.y;
}

int Sprite::getX()
{
	return this->x;
}

int Sprite::getY()
{
	return this->y;
}

Vector2i Sprite::getPosition()
{
	return Vector2i(this->x, this->y);
}

void Sprite::setSpriteData(SpriteData* sd)
{
	this->spriteData = sd;
}

SpriteData* Sprite::getSpriteData()
{
	return this->spriteData;
}

void Sprite::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

void Sprite::setScale(int scale)
{
	this->scale = scale;
}

int Sprite::getWidth()
{
	return this->x;
}

int Sprite::getHeight()
{
	return this->y;
}

void Sprite::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect;
	rect.w = this->width * this->scale;
	rect.h = this->height * this->scale;
	rect.x = this->x;
	rect.y = this->y;

	SDL_RenderCopyEx(renderer,
			this->spriteData->texture,
			nullptr,
			&rect,
			0,
			nullptr,
			SDL_FLIP_NONE);
}
