#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

struct Renderer
{
    static void renderSingleSprite(SDL_Renderer* renderer, 
          SDL_Texture* sprite, int x, int y, 
          int width, int height);
    
    static void renderSingleEntity(SDL_Renderer* renderer, 
          class Entity* entity);
    
    static void renderSpriteData(SDL_Renderer* renderer, 
          class SpriteData* sd, int x, int y);
    
    static void drawText(SDL_Renderer* renderer, 
          const char* string, int x, int y);

    static bool loadFont(const char* path);
    static bool loadSpriteSheet(SDL_Renderer* renderer, const char* path);
    
    static SDL_Texture* loadSprite(SDL_Renderer* renderer,
          const char* path);
   

    static SDL_Texture* spritesheet;
    static TTF_Font* font;
};

#endif // RENDERER_H
