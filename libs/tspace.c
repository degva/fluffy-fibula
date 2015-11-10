#include <tspace.h>

void TSpace_init(TSpace * S) {
    S->descubierto = false;
    S->tipoDeSpace = 0;
    //S->relleno = NULL; 
    S->surface = SDL_LoadBMP( "img/tile.bmp" );
    // S->spaces = (TSpace *) malloc(sizeof(TSpace)*6);
};

void TSpace_render(TSpace * Ts, TCoord * Tc, SDL_Surface * S) {
  int i;

  SDL_Rect dst;
  dst.x = Tc->x;
  dst.y = Tc->y;
  dst.w = SPACESIZE;
  dst.h = SPACESIZE;

  SDL_BlitSurface(Ts->surface, NULL, S, &dst);
}

void Space_changeBackground(TSpace * Ts, SDL_Surface * S) {

}
