#ifndef _TMAP_H_
#define _TMAP_H_

#include <tlibs.h>

typedef struct {
  SDL_Surface * map_tile;
} TMap;

void _putTile(TMap * M, SDL_Surface * S, int x, int y, int w, int h);
void TMap_init(TMap * M);
void TMap_Render(TMap * M, SDL_Surface * S);

#endif
