#ifndef _TMAP_H_
#define _TMAP_H_

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  SDL_Surface * map_tile;
} TMap;

void TMap_init(TMap * M);

#endif
