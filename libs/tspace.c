#include <space.h>

void TSpace_init(TSpace * S) {
    S->descubierto = false;
    S->tipoDeSpace = 0;
    S->relleno = NULL;
    S->spaces = (TSpace *) malloc(sizeof(TSpace)*6);
};

void TSpace_render(TSpace * Ts, SDL_Surface * S) {
  int i;
  
  SDL_BlitSurface(Ts->space, NULL, S, NULL);
  
  // Show the texts
  //for (i=0; i<MENU_TOTAL_BUTTONS; i++) {
  // TButton_render( *(M->buttons+i), F, S);
  }
}
