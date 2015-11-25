#ifndef _DISCARD_H
#define _DISCARD_H

#include <carta.h>
#include <tlist.h>

typedef struct {
	TLista *list;
} TCardDiscard;

TCardDiscard * TCardDiscard_new(SDL_Renderer *);
void TCardDiscard_addElement(TCardDiscard *discard , TCard * carta);
void TCardDiscard_shuffle(TCardDiscard * discard);

#endif
