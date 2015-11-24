#ifndef _TTILES_H_
#define _TTILES_H_

/*
 * Tipo TILES
 * es el que tiene 7 espaces y es por donde se mueve cada heroe
 * y enemigo
 */

#include <tlibs.h>
#include <tspace.h>

#define NUM_SPACES 7


typedef struct {
  TSpace * spaces[NUM_SPACES];
} TTiles;

void TTiles_init(TTiles*, SDL_Renderer *, TEnemy *);
void TTiles_Render(TTiles *, SDL_Renderer *, TCoord * Tc[NUM_SPACES]);
int TTiles_handleEvent(TTiles *, SDL_Event *, TCoord * Tc[NUM_SPACES], int * cS); 

#endif
