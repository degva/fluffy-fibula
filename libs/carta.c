#include <carta.h>

TCard * TCard_new(char *name,int points,int type, char * img, SDL_Renderer * R)
{
  TCard * carta;
  carta = malloc( sizeof (TCard));
  carta->name = name;
  carta->points = points;
  carta->type = type;

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

void TCard_handleEvent(TCard * C, TCoord * Tc, SDL_Event * E,  TCard ** p) {
  if ( E->type == SDL_MOUSEBUTTONDOWN ) {
    // Get mouse position
    int x, y;
    SDL_GetMouseState( &x, &y );

    // Check if mouse is in button
    bool inside = true;
    // Mouse if left of the button
    if (x < 600 + Tc->x) {
      inside = false;
    // mose is right of the button
    } else if (x > 600 + Tc->x + 32) {
      inside = false;
    // mouse is above the button
    } else if (y < Tc->y) {
      inside = false;
    } else if (y > Tc->y + 32) {
      inside = false;
    }

    // Mouse is outside button
    if (inside) {
      *p = C;
    }
  }
}

void TCard_render(TCard * C, TCoord * Tc, SDL_Renderer * R) {

  SDL_Rect dst;
  dst.x = Tc->x;
  dst.y = Tc->y;
  dst.w = 32;
  dst.h = 32;

  // printf(" - x: %d | y: %d | w: %d | h %d \n", dst.x, dst.y, dst.w, dst.h);

  SDL_RenderCopy(R, C->img, NULL, &dst);
  if (C->img == NULL) {
    printf("\t- ERROR at TCard_render");
  }
}
