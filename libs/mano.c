#include "mano.h"

TCardMano * TCardMano_new(SDL_Renderer * R)
{
	TCardMano * mano;
	mano = malloc(sizeof(TCardMano));
	mano->list = t_mlist_new();

  mano->action = TActionCard_new();
  mano->discard = TCardDiscard_new(R);
  mano->level = 2;

  TCardDiscard_shuffle(mano->discard);
  TCardAction_takeFromDiscard(mano->action, mano->discard);
  TCardMano_takeFromAction(mano, M->level);

	return mano;
}

void TCardMano_takeFromAction(TCardMano * mano, int num) {
  int i;
  TNodo * cardNodo;
  for (i=0; i<num; i++) {
    // tomamos un numero x de cartas siempre y cuando hayan las suficientes
    if (!t_mlist_is_empty(action)) {
      cardNodo = TLista_pop(mano->action->list);
      TCardMano_addElement(mano->list, cardNodo->elem);
    } else {
      // en caso que se acabe el action, salimos del lugar
      break;
    }
  }
}

void TCardMano_sendToDiscard(TCardMano * mano, int num) {
  TNodo * card = TLista_takeNodo(mano->list, num);
  TDiscard_addElement(mano->discard, card);
}

void handleEvent(TCardMano * M) {
  if (TLista_tamanho(M) == 0 && TLista_tamanho(M->action)) {
    TCardDiscard_shuffle(mano->discard);
    TCardAction_takeFromDiscard(mano->action, mano->discard);
    TCardMano_takeFromAction(mano, M->level);
  }
}

void TCardMano_selectCard(TCardMano * M, int pos) {
  int i;
  TNodo * nodo = M->list->inicio;
  for (i=0; i<pos; i++) {
    nodo = nodo->sig; 
  }
  TCard_selectToggle(nodo->elem);
}

void TCardMano_render(TCardMano * M, TList * Cds) {

}
