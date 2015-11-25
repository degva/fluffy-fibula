#ifndef MANO_H
#define	MANO_H

#include <tlibs.h>
#include <tlist.h>
#include <action.h>
#include <discard.h>

typedef struct {
	TLista *list;
  TCardAction * action;
  TCardDiscard * discard;
  int level;
} TCardMano;

TCardMano * TCardMano_new(SDL_Renderer *, int);

void TCardMano_takeFromAction(TCardMano *, int);
void TCardMano_sendToDiscard(TCardMano *, TLista * );
void TCardMano_handleEvent(TCardMano *, TLista *, SDL_Event *, TLista *);
void TCardMano_selectCard(TCardMano * M, int pos);
void TCardMano_render(TCardMano *, TLista * Coord, SDL_Renderer *);



#endif	/* MANO_H */
