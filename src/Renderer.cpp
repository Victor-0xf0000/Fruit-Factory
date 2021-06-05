#include <Core/Renderer.h>
#include <Core/ErrorLog.h>
#include <Core/Sprite.h>

SDL_Texture* Renderer::spritesheet;

bool Renderer::loadSpriteSheet(SDL_Renderer* renderer, const char* path)
{
    Renderer::spritesheet = IMG_LoadTexture(renderer, path);



    if (!renderer)
    {
        fERROR("Undefined renderer");
        return false;
    }

    if (!Renderer::spritesheet)
    {
        fERROR("Cannot find ", path);
        return false;
    }
    return true;
}

SDL_Texture* Renderer::loadSprite(SDL_Renderer* renderer, const char* path)
{
    SDL_Texture* text = IMG_LoadTexture(renderer, path);

    if (!renderer)
    {
        fERROR("Undefined renderer");
        return nullptr;
    }

    if (!text)
    {
        fERROR("Cannot find", path);
        return nullptr;
    }

    return text;
}

void Renderer::render(SDL_Renderer* renderer, SpriteData* sprite)
{
    // TODO: Move src rect and dst rect to SpriteData - maybe
    SDL_Rect srcRect = {.x = sprite->ssx, .y = sprite->ssy, .w = sprite->width, .h = sprite->height};
    SDL_Rect desRect = {.x = sprite->x, .y = sprite->y, .w = sprite->width * sprite->scale, .h = sprite->height * sprite->scale};

    // TODO: support angles
    SDL_RenderCopy(renderer, Renderer::spritesheet, &srcRect, &desRect);
}

void Renderer::renderSingleSprite(SDL_Renderer* renderer, SDL_Texture* sprite, int x, int y, int width, int height)
{
    SDL_Rect srcRct = {.x = x, .y = x, .w = width, .h = height};

    SDL_RenderCopy(renderer, sprite, nullptr, &srcRct);
}