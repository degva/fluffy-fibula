#include <sidemenu.h>

TSideMenu * TSideMenu_new(TMap * M) {
  TSideMenu * Tsm;
  Tsm = (TSideMenu *) malloc(sizeof(TSideMenu));

  Tsm->mapa = M;
}

