#ifndef CLOCK_H
#define CLOCK_H

#include <SDL2/SDL.h>

struct Clock
{
   uint32_t ticks_count = 0.f;
   float delta = 0.f;

   void tick()
   {
      delta = (SDL_GetTicks() - ticks_count) / 1000.f;
      ticks_count = SDL_GetTicks();
   }
};

#endif // CLOCK_H
