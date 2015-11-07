#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// FIXME ver de usar tlibs.h y ademas de otro nombre para enemigos.h
#include <enemigos.h>

enum tiposDeSpace {
    PLAIN = 2,
    FOREST = 3,
    HILL = 4,
    SWAMP = 5,
    UNREACHABLE = 1000
}

typedef struct _TSpace {
    bool descubierto;
    int tipoDeSpace;
    // este es el Tipo Entidad General en enemigos.h
    TEntGen * relleno;
    struct _TSpace ** spaces;
} TSpace;

void TSpace_init(TSpace * S);
TSpace * TSpace_createSpace();
