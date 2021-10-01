#ifndef SPRITE_H
#define SPRITE_H

struct SpriteData
{
  int width = 0, height = 0;
  int ssx = 0, ssy = 0; // Sprite sheet x and y
  int scale = 1;
};

static SpriteData createSpriteData(int width, int height,
    int ssx, int ssy, int scale)
{
  SpriteData sd = {.width = width, .height = height, .ssx = ssx, .ssy = ssy,
    .scale = scale};
  return sd;
}

#endif // SPRITE_H
