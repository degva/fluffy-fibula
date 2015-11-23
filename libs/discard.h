#ifndef _DISCARD_H
#define _DISCARD_H

#include <carta.h>
typedef struct _TCardDiscard TCardDiscard ;

struct _TCardDiscard{
	TLista *list;
};

TCardDiscard * TCardDiscard_new(SDL_Renderer *);
void TCardDiscard_addElement(TCardDiscard *discard , TCard * carta);
void TCardDiscard_shuffle(TCardDiscard * discard);

#endif
