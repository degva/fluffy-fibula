#include "discard.h"
#include "tmlist.h"
TCardDiscard * TCardDiscard_new(SDL_Renderer * R) {
  int i;
  TCardDiscard * discard;
  discard = malloc(sizeof(TCardDiscard));
  discard->list = TLista_init();

  TCard * card;
  for(j=0;j<8;j++){
    for ( i = 0 ; FLUFLY_CARDS[i].name != NULL; i++){
      carta = TCart_new ( FLUFLY_CARDS[i].name,
          FLUFLY_CARDS[i].points+j,
          FLUFLY_CARDS[i].type,
          FLUFLY_CARDS[i].img,
          R);
      TLista_insertar(discard->list, carta);
    }
  }

  return discard;
}

void TCardDiscard_addElement (TCardDiscard * discard, TCard * carta) {
  TLista_insertar(discard->list, carta);
}

void TCardDiscard_shuffle (TCardDiscard * D) {
  int n = TLista_tamanho(D->list);
  int i;
  for (i =0; i<n-1; i++) {
    int j = i + rand() / (RAND_MAX / (n-i) +1);
    TLista_swapNodos(D->lista, i, j);
  }
}


