#include <theroe.h>

THeroe * THeroe_new(SDL_Renderer * R){
  THeroe * pj;
  pj = malloc( sizeof (TPJ));
  pj->def= 10;
  pj->exp = 1;
  pj->name = "Heroe";
  pj->nivel = 1;
  
  SDL_Surface * surf;
  surf = IMG_Load( "img/heroe.png" );
  if (surf == NULL)
    printf("Heroe was not loaded!!");
  pj->img = SDL_CreateTextureFromSurface( R, surf );
  
  SDL_FreeSurface(surf);
  
  return pj;
};

void THeroe_render(THeroe * H, TCoord * Tc, SDL_Renderer * R) {

  SDL_Rect dst;
  dst.x = Tc->x;
  dst.y = Tc->y;
  dst.w = SPACESIZE;
  dst.h = SPACESIZE;

  SDL_RenderCopy(R, H->img, NULL, &dst);
  if (H->img == NULL) {
    printf("\t- ERROR In the img of heroe");
  }
}
