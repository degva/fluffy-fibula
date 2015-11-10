#include <space.h>

void TSpace_init(TSpace * S) {
    S->descubierto = false;
    S->tipoDeSpace = 0;
    S->relleno = NULL;
    S->spaces = (TSpace *) malloc(sizeof(TSpace)*6);
}

