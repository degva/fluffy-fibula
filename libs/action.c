#include "action.h"

TCardAction * TCardAction_new()
{
  TCardAction * Action;
  Action = malloc(sizeof(TCardAction));
  Action->list = NULL;
  return Action;
}

void TCardAction_takeFromDiscard(TCardAction * A, TCardDiscard * D) {
  A->list = D->list;
  D->list = malloc(sizeof(TLista));
  TLista_init(D->list);
}

int TCardAction_numCards(TCardAction * A) {
  return TLista_tamanho(A->list);
}
