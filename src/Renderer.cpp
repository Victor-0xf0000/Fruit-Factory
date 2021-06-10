#include <Core/Renderer.h>
#include <Core/ErrorLog.h>
#include <Core/Sprite.h>
#include <Core/Entity.h>

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

void Renderer::renderSingleEntity(SDL_Renderer* renderer, Entity* entity)
{
    SpriteData sd = *entity->getSpr();
    SDL_Rect srcRect = {.x = sd.ssx, .y = sd.ssy, .w = sd.width, .h = sd.height};
    SDL_Rect desRect = {.x = entity->getX(), .y = entity->getY(), .w = sd.width * sd.scale, .h = sd.height * sd.scale};

    SDL_RenderCopy(renderer, Renderer::spritesheet, &srcRect, &desRect);
}

void Renderer::renderSingleSprite(SDL_Renderer* renderer, SDL_Texture* sprite, int x, int y, int width, int height)
{
    SDL_Rect srcRct = {.x = x, .y = x, .w = width, .h = height};

    SDL_RenderCopy(renderer, sprite, nullptr, &srcRct);
}