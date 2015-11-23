#include <carta.h>

TCard * TCard_new(char *name,int points,int type, char * img, SDL_Renderer * R)
{	
  TCard * carta;
  carta = malloc( sizeof (TCard));
  carta->name = name;
  carta->points = points;
  carta->type = type;
  carta->img = img;

  SDL_Surface * surf;
  surf = IMG_Load(img);
  if (surf == NULL)
    printf("Card image was not loaded!!");
  carta->img = SDL_CreateTextureFromSurface( R, surf );
  SDL_FreeSurface(surf);

  return carta;

};

void TCard_modify_points(TCard * carta , int points) {
  carta->points = carta->points + points;
}

void TCard_selectToggle(TCard * C) {
  // wonder if this is going to work
  C->selected = !C->selected;
}

void TCard_render(TCard * C, SDL_Renderer * R, TCoord * Tc) {

  SDL_Rect dst;
  dst.x = Tc->x;
  dst.y = Tc->y;
  dst.w = SPACESIZE;
  dst.h = SPACESIZE;

  // printf(" - x: %d | y: %d | w: %d | h %d \n", dst.x, dst.y, dst.w, dst.h);

  SDL_RenderCopy(R, C->img, NULL, &dst);
  if (C->img == NULL) {
    printf("\t- ERROR at TCard_render");
  }
}

