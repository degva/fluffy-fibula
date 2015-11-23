#ifndef MANO_H
#define	MANO_H

#include <tlibs.h>
#include <tlist.h>
#include <action.h> 
#include <discard.h>

typedef struct _TCardMano TCardMano;
struct _TCardMano{
	TLista *list;
  TCardAction * action;
  TCardDiscard * discard;
  int level;
};

TCardMano * TCardMano_new(SDL_Renderer *);

void TCardMano_takeFromAction(TCardAction *, int);
void TCardMano_sendToDiscard(TCardMano *, int);
void TCardMano_handleEvent(TCardMano *);
void TCardMano_selectCard(TCardMano * M, int pos) {

//void TCardMano_render(TCardMano *, TList * Coord);



#endif	/* MANO_H */

