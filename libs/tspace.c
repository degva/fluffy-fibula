#include <space.h>

void TSpace_init(TSpace * S) {
    S->descubierto = false;
    S->tipoDeSpace = 0;
    S->relleno = NULL;
    S->spaces = (TSpace *) malloc(sizeof(TSpace)*6);
}

TSpace * TSpace_createSpace() {
    TSpace * space;
    space = (TSpace *) malloc(sizeof(TSpace));

    TSpace_init(space);    
}





