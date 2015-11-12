#include <tspace.h>

void TSpace_init(TSpace * S, SDL_Renderer * R) {
    S->descubierto = false;
    S->tipoDeSpace = 0;
    //S->relleno = NULL; 
    // Load tile surface
    SDL_Surface * surf;
    surf = IMG_Load( "img/tile.png" );
    S->texture = SDL_CreateTextureFromSurface( R, surf );
    SDL_FreeSurface(surf);
    // S->spaces = (TSpace *) malloc(sizeof(TSpace)*6);
};

void TSpace_render(TSpace * Ts, TCoord * Tc, SDL_Renderer * R) {
  int i;

  SDL_Rect dst;
  dst.x = Tc->x;
  dst.y = Tc->y;
  dst.w = SPACESIZE;
  dst.h = SPACESIZE;

  SDL_RenderCopy(R, Ts->texture, NULL, &dst);
}

void Space_changeBackground(TSpace * Ts, SDL_Renderer * R) {

}
