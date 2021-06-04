#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct Renderer
{
    static void render(SDL_Renderer* renderer, class SpriteData* sprite);
    static bool loadSpriteSheet(SDL_Renderer* renderer, const char* path);

    static SDL_Texture* spritesheet;
};

#endif // RENDERER_H