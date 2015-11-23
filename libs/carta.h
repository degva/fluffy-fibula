#include <tlibs.h>

#ifndef CARTAST_H
#define CARTAST_H

static TCard FLUFLY_CARDS[] = { 
  {"Move",2,1,"img/move.png"},
  {"Attack",2,2,"img/attack.png"},
  {"Defend",2,3,"img/defend.png"},
  {"Heal",2,4,"img/heal.png"},
  {"Buy",2,5,"img/buy.png"},
  {NULL,0,0,NULL}
};

typedef struct {
	char *name ;
	int points;
	int type;
	SDL_Texture *img;
  bool selected;
} TCard;

TCard * TCard_new(char *name, int points, int type, char *img);

// -- Por que???
// TArray * TCard_create_carts();

void TCard_modify_points (TCard * , int points);
void TCard_selectToggle(TCard *);
void TCard_render (TCard *, SDL_Renderer *, TCoord *);

#endif	/* CARTA_H */

