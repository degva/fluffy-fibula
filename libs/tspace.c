#include <tspace.h>

void TSpace_init(TSpace * S, SDL_Renderer * R) {
    S->descubierto = false;
    S->tipoDeSpace = 0;
    S->currentSprite = SPACE_TILE_OFF;
    //S->relleno = NULL;


    // Load tile surface for normal
    SDL_Surface * surf;
    surf = IMG_Load( "img/tile.png" );
    if (surf == NULL)
      printf("Tile were not loaded!!");
    S->texture[SPACE_TILE_OFF] = SDL_CreateTextureFromSurface( R, surf );
    // Load tile surface for hover
    surf = IMG_Load( "img/tile-hover.png" );
    if (surf == NULL)
      printf("Tile were not loaded!!");
    S->texture[SPACE_TILE_HOVER] = SDL_CreateTextureFromSurface( R, surf );
    
    SDL_FreeSurface(surf);
    // S->spaces = (TSpace *) malloc(sizeof(TSpace)*6);
};

void TSpace_render(TSpace * Ts, TCoord * Tc, SDL_Renderer * R) {

  SDL_Rect dst;
  dst.x = Tc->x;
  dst.y = Tc->y;
  dst.w = SPACESIZE;
  dst.h = SPACESIZE;

  // printf(" - x: %d | y: %d | w: %d | h %d \n", dst.x, dst.y, dst.w, dst.h);

  SDL_RenderCopy(R, Ts->texture[Ts->currentSprite], NULL, &dst);
  if (Ts->texture[Ts->currentSprite] == NULL) {
    printf("\t- ERROR");
  }
}

void TSpace_handleEvent(TSpace * Ts, SDL_Event * e, TCoord * coord) {
  
}
