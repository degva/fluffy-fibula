#ifndef THEROE_H
#define	THEROE_H

#include <tlibs.h>
#include <tlist.h>

typedef struct {
	char *name ;
	int def;
  int exp;
  int nivel;
	SDL_Texture *img;
} THeroe;

THeroe * THeroe_new(SDL_Renderer * R);
void THeroe_render(THeroe * H, TCoord * Tc, SDL_Renderer * R);

#endif	/* PJ_H */

