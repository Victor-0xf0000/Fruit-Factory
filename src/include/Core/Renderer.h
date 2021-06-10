#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Renderer
{
    static void renderSingleSprite(SDL_Renderer* renderer, SDL_Texture* sprite, int x, int y, int width, int height);
    static void renderSingleEntity(SDL_Renderer* renderer, class Entity* entity);
    static bool loadSpriteSheet(SDL_Renderer* renderer, const char* path);
    static SDL_Texture* loadSprite(SDL_Renderer* renderer, const char* path);
    static SDL_Texture* spritesheet;
};

#endif // RENDERER_H