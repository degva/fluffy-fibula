#include <tspace.h>

void TSpace_init(TSpace * S, SDL_Renderer * R, TEnemy * E) {
  int r = rand() % 5;
  S->descubierto = false;
  S->tipoDeSpace = 0;
  S->currentSprite = SPACE_TILE_OFF;
  S->enemy = E;
  // Load tile surface for normal
  SDL_Surface * surf;
  switch ( r ) {
    case 0 :
      surf = IMG_Load( "img/t-plaina.png" );
      break;
    case 1 :
      surf = IMG_Load( "img/t-forest.png" );
      break;
    case 2 :
      surf = IMG_Load( "img/t-hill.png" );
      break;
    case 3 :
      surf = IMG_Load( "img/t-swamp.png" );
      break;
    case 4 :
      surf = IMG_Load( "img/t-unreachable.png" );
      break;
  }

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

  if (Ts->enemy != NULL) {
    TEnemy_render(Ts->enemy, Tc, R);
  }
}

void TSpace_handleEvent(TSpace * Ts, SDL_Event * e, TCoord * coord) {
  if (
      e->type == SDL_MOUSEMOTION
      //|| e->type == SDL_MOUSEBUTTONDOWN
     ) {
    // Get mouse position
    int ex, ey;
    SDL_GetMouseState( &ex, &ey );
    // Check if mouse is in button
    bool inside = false;

    if (
        ex > coord->x &&
        ex < coord->x + SPACESIZE &&
        ey > 0.5012*(-ex + coord->x) + coord->y + 0.2506*SPACESIZE &&
        ey < 0.5012*(ex - coord->x) + coord->y + 0.7494*SPACESIZE &&
        ey > 0.5012*(ex - coord->x) + coord->y - 0.2506*SPACESIZE &&
        ey < 0.5012*(-ex + coord->x + SPACESIZE) + coord->y + 0.7494*SPACESIZE
       )
    {
      inside = true;
    }

    // Mouse is outside button
    if (!inside) {
      Ts->currentSprite = SPACE_TILE_OFF;
    }
    // Mouse is inside button
    else {
      switch (e->type) {
        case SDL_MOUSEMOTION:
          Ts->currentSprite = SPACE_TILE_HOVER;
          break;
          /*
             case SDL_MOUSEBUTTONDOWN:
             B->currentSprite = BUTTON_SPRITE_MOUSE_DOWN;
             break;
             */
      }
    }
  }
}
