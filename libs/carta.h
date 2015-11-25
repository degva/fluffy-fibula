#ifndef CARTAST_H
#define CARTAST_H

#include "tlibs.h"
#include "tlist.h"

typedef struct {
	char *name ;
	int points;
	int type;
	SDL_Texture *img;
  SDL_Texture *selec;
  bool selected;
} TCard;

TCard * TCard_new(char *name, int points, int type, char *img, SDL_Renderer *);

// -- Por que???
// TArray * TCard_create_carts();

void TCard_modify_points (TCard * , int points);
void TCard_selectToggle(TCard *);
void TCard_handleEvent(TCard *, TCoord *, SDL_Event *, TLista *);
void TCard_render (TCard *, TCoord *, SDL_Renderer *);

#endif	/* CARTA_H */
