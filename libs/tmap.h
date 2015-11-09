#ifndef _TMAP_H_
#define _TMAP_H_

/*
 * Tipo MAPA
 * este tipo es para la creacion de un mapa para el juego.
 * Tiene una mapa de coordenadas para cada tile
 */

#include <tlibs.h>
#include <ttiles.h>
#define NUMBER_OF_TILES 8
#define SPACES_X_TILE 7

typedef struct {
  int x;
  int y;
} TCoord;

typedef struct {
  TCoord *coords[NUMBER_OF_TILES][SPACES_X_TILE];
  TTiles *tiles[NUMBER_OF_TILES];
} TMap;

// Initialize a Map
void TMap_init(TMap * M);
// Renders a Map
void TMap_Render(TMap * M, SDL_Surface * S);
// Handles the Map
void TMap_handleEvent(TMap * M, SDL_Event * e);

#endif
