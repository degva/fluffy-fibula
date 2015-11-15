#ifndef _TSPACE_H_
#define _TSPACE_H_

#include <tlibs.h>
#include <tentstr.h>

#define MAXSPACES 6
#define SPACESIZE 50

enum tiposDeSpace {
    PLAIN = 2,
    FOREST = 3,
    HILL = 4,
    SWAMP = 5,
    UNREACHABLE = 1000
};
enum mousePos {
  SPACE_TILE_OFF,
  SPACE_TILE_HOVER,
  SPACE_TILE_TOTAL
};

typedef struct {
  int x;
  int y;
} TCoord;

typedef struct _TSpace {
    bool descubierto;
    int tipoDeSpace;
    int currentSprite;
    // este es el Tipo Entidad General en enemigos.h
    // TEntGen * relleno;
    struct _TSpace * spaces[MAXSPACES];
    SDL_Texture * texture[SPACE_TILE_TOTAL]; // We will use other in case of hover
} TSpace;

// Crea un space simple, de manera random
// Mira este link: http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
// Debe usar el enum tiposDeSpace para create el space
// Nota: debe poner spaces en espacios en blanco
void TSpace_init(TSpace * S, SDL_Renderer * R);

// hace un render en el Surface S
// ver tmenu.c funcion TMenu_onRender() para ver funcionalidad
void TSpace_render(TSpace * Ts, TCoord * Tc, SDL_Renderer * R);

// Llamado por TMap_handleEvent
void TSpace_handleEvent(TSpace * Ts, SDL_Event * e, TCoord * coord);


#endif
