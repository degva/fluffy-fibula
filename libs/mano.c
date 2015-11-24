#include "mano.h"

TCardMano * TCardMano_new(SDL_Renderer * R, int level) {
  TCardMano * mano;
  mano = malloc(sizeof(TCardMano));
  mano->list = malloc(sizeof(TLista));
  TLista_init(mano->list);

  mano->action = TCardAction_new();
  mano->discard = TCardDiscard_new(R);
  mano->level = 2;

  //TCardDiscard_shuffle(mano->discard);
  TCardAction_takeFromDiscard(mano->action, mano->discard);
  TCardMano_takeFromAction(mano, level);

  return mano;
}

void TCardMano_takeFromAction(TCardMano * mano, int num) {
  int i;
  TNodo * cardNodo;
  for (i=0; i<num; i++) {
    // tomamos un numero x de cartas siempre y cuando hayan las suficientes
    if (!TLista_estaVacia(mano->action->list)) {
      cardNodo = TLista_pop(mano->action->list);
      TLista_insertar(mano->list, cardNodo->elem);
    } else {
      // en caso que se acabe el action, salimos del lugar
      break;
    }
  }
}

void TCardMano_sendToDiscard(TCardMano * mano, int num) {
  TNodo * card = TLista_takeNodo(mano->list, num);
  TCardDiscard_addElement(mano->discard, card->elem);
}

void TCardMano_handleEvent(TCardMano * M, TLista*L, SDL_Event * E, TCard ** p) {
  TNodo * coord;
  coord = L->inicio;
  TNodo * carta;
  carta = M->list->inicio;

  while (carta != NULL && coord != NULL) {
    TCard_handleEvent(carta->elem, coord->elem, E, &*p);
    carta = carta->sig;
    coord = coord->sig;
  }

  if (TLista_tamanho(M->list) == 0 && TLista_tamanho(M->action->list)) {
    TCardDiscard_shuffle(M->discard);
    TCardAction_takeFromDiscard(M->action, M->discard);
    // TODO: The 5 should be actually a pointer to the  level in the capp
    TCardMano_takeFromAction(M, 5);
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

void TCardMano_render(TCardMano * M, TLista * Cds, SDL_Renderer * R) {
  TNodo * coord;
  coord = Cds->inicio;
  TNodo * carta;
  carta = M->list->inicio;
  while (carta != NULL &&  coord != NULL) {
    TCard_render(carta->elem, coord->elem, R);
    carta = carta->sig;
    coord = coord->sig;
  }
}
