#ifndef ACTION_H
#define ACTION_H

#include <tlibs.h>
#include <carta.h>
#include <discard.h>

typedef struct _TCartAction{
	TLista *list;
} TCartAction;

TCartAction * TCartAction_new();
void TCardAction_takeFromDiscard(TCardAction *, TCardDiscard *);
int TCardAction_numCards(TCardAction *);

#endif	/* ACTION_H */

