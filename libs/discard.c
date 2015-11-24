#include <discard.h>

TCardDiscard * TCardDiscard_new(SDL_Renderer * R) {

  char *names[5] = {"Move", "Attack", "Defend", "Heal", "Buy"};
  int points[5] = {2,2,2,2,2};
  int type[5] = {1,2,3,4,5};
  char *imagenes[5] = {"img/c-move.png", "img/c-attack.png", "img/c-defend.png", "img/c-heal.png", "img/c-buy.png"};

  int i, j;
  TCardDiscard * discard;
  discard = malloc(sizeof(TCardDiscard));
  discard->list = malloc(sizeof(TLista));
  TLista_init(discard->list);

  TCard * carta;
  for(j=0;j<8;j++){
    for ( i = 0 ; i < 5; i++){
      carta = TCard_new ( names[i],
          points[i],
          type[i],
          imagenes[i],
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
    int j = i + rand() / (RAND_MAX / (n-i) +1) - 2;
    TLista_swapNodos(D->list, i, j);
  }
}
