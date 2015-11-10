#include <tspace.h>

void TSpace_init(TSpace * S) {
    S->descubierto = false;
    S->tipoDeSpace = 0;
    //S->relleno = NULL;
}

void TSpace_render(TSpace * Ts, TCoord * Tc, SDL_Surface * S) {
}

void Space_changeBackground(TSpace * Ts, SDL_Surface * S) {
}
