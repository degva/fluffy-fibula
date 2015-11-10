#ifndef _TSPACE_H_
#define _TSPACE_H_

#include <tlibs.h>
// FIXME ver de usar tlibs.h y ademas de otro nombre para enemigos.h
#include <enemigos.h>

#define MAXSPACES 6
#define SPACESIZE 40

enum tiposDeSpace {
    PLAIN = 2,
    FOREST = 3,
    HILL = 4,
    SWAMP = 5,
    UNREACHABLE = 1000
};
typedef struct {
  int x;
  int y;
} TCoord;

typedef struct _TSpace {
    bool descubierto;
    int tipoDeSpace;
    // este es el Tipo Entidad General en enemigos.h
    // TEntGen * relleno;
    struct _TSpace * spaces[MAXSPACES];
    SDL_Surface * surface;
} TSpace;

// Crea un space simple, de manera random
// Mira este link: http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
// Debe usar el enum tiposDeSpace para create el space
// Nota: debe poner spaces en espacios en blanco
void TSpace_init(TSpace * S);

// hace un render en el Surface S
// ver tmenu.c funcion TMenu_onRender() para ver funcionalidad
void TSpace_render(TSpace * Ts, TCoord * Tc, SDL_Surface * S);

// Llamado por TMap_handleEvent
void TSpace_changeBackground(TSpace * Ts, SDL_Surface * S);


#endif
