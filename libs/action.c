#include "action.h"

TCartAction * TCartAction_new()
{
	TCartAction * Action;
	Action = malloc (sizeof (TCartAction));
	Action->list = NULL;
	return Action;
}

void TCardAction_takeFromDiscard(TCardAction * A, TCardDiscard * D) {
  A->list = D->list;
  D->list = TLista_init();
}

int TCardAction_numCards(TCardAction * A) {
  return TLista_tamanho(A->list);
}
