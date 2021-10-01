#include <Core/Renderer.h>
#include <Core/ErrorLog.h>
#include <Core/Sprite.h>
#include <Core/Entity.h>

SDL_Texture* Renderer::spritesheet = nullptr;
SDL_Texture* Renderer::alphaSpritesheet = nullptr;
TTF_Font* Renderer::font = nullptr;

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
        fERROR("Cannot find");
        printf("%s\n", path);
        return false;
    }
    
    // if you do alphaSpritesheet = spritesheet, the spritesheet would be opace too
    Renderer::alphaSpritesheet = IMG_LoadTexture(renderer, path);
    SDL_SetTextureAlphaMod(Renderer::alphaSpritesheet, 190);
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
        fERROR("Cannot find");
        printf("%s\n", path);
        return nullptr;
    }

    return text;
}

void Renderer::renderSingleEntity(SDL_Renderer* renderer, Entity* entity)
{
    SpriteData sd = entity->getSpr();
    SDL_Rect srcRect = {.x = sd.ssx, .y = sd.ssy, .w = sd.width, .h = sd.height};
    SDL_Rect desRect = {.x = entity->getX(), .y = entity->getY(), .w = sd.width * sd.scale, .h = sd.height * sd.scale};

    SDL_RenderCopy(renderer, Renderer::spritesheet, &srcRect, &desRect);
}

void Renderer::renderSingleSprite(SDL_Renderer* renderer, SDL_Texture* sprite, int x, int y, int width, int height)
{
    SDL_Rect dstRct = {.x = x, .y = y, .w = width, .h = height};

    SDL_RenderCopy(renderer, sprite, nullptr, &dstRct);
}

void Renderer::renderSpriteData(SDL_Renderer* renderer, SpriteData* sd, int x, int y)
{
    SDL_Rect srcRect = {.x = sd->ssx, .y = sd->ssy, .w = sd->width, .h = sd->height};
    SDL_Rect dstRect = {.x = x, .y = y, .w = sd->width * sd->scale, .h = sd->height * sd->scale};

    SDL_RenderCopy(renderer, Renderer::spritesheet, &srcRect, &dstRect);
}

void Renderer::renderTransparentSpriteData(SDL_Renderer* renderer, SpriteData* sd, int x, int y)
{

    SDL_Rect srcRect = {.x = sd->ssx, .y = sd->ssy, .w = sd->width, .h = sd->height};
    SDL_Rect dstRect = {.x = x, .y = y, .w = sd->width * sd->scale, .h = sd->height * sd->scale};

    SDL_RenderCopy(renderer, Renderer::alphaSpritesheet, &srcRect, &dstRect);
}

void Renderer::drawText(SDL_Renderer* renderer, const char* string, int x, int y)
{
    SDL_Color color = {.r = 5, .g = 3, .b = 9, .a = 255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Renderer::font, string, color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src = {.x = 0, .y = 0, .w = surfaceMessage->w, .h = surfaceMessage->h};
    SDL_Rect dst = {.x = x, .y = y, .w = src.w, .h = src.h};

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
}

bool Renderer::loadFont(const char* path)
{
    Renderer::font = TTF_OpenFont(path, 24);
    if (!Renderer::font)
    {
        printf("Cannot load font\n");
        exit(0);
    }

    return true;
}
