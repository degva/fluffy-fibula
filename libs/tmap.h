#ifndef _TMAP_H_
#define _TMAP_H_

#include <tlibs.h>

typedef struct {
  SDL_Surface * map_tile;
} TMap;

void TMap_init(TMap * M);

#endif
