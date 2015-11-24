#include <sidemenu.h>

TSideMenu * TSideMenu_new(TTF_Font * F, THeroe * hero, TCardMano * cartas, TMap * M, SDL_Renderer * R) {
  TSideMenu * sm;
  sm = (TSideMenu *) malloc(sizeof(TSideMenu));

  // Init background images of the menu
  SDL_Surface * surf;
  surf = IMG_Load("img/b-side.png");
  if (surf == NULL)
    printf("Card image was not loaded!!");
  sm->background = SDL_CreateTextureFromSurface( R, surf );
  SDL_FreeSurface(surf);

  sm->mapa = M;
  sm->cartas = cartas;
  sm->hero = hero;
  sm->button = malloc(sizeof(TButton));
  TButton_init(sm->button, F , "Pagar", R);
  sm->cartasCoords = malloc(sizeof(TLista));
  TLista_init(sm->cartasCoords);

  // TODO Create the cartasCoords dinamically. Only need to do it once!
  int i, x, y;
  x = 11;
  y = 11;
  int j = 0;
  for (i = 0; i < 40; i++) {
    TCoord * coord;
    coord = malloc(sizeof(TCoord));
    coord->x = x + 32*i + i;
    coord->y = y + 32*j + j;
    if ((i+1) % 9 == 0) {
      j++;
    }

    TLista_insertar(sm->cartasCoords, coord);
  }
  return sm;
}

void TSideMenu_handleEvent(TSideMenu * SM, SDL_Event * E) {
  // if mouse is inside one of the cards
  // -- check if it has been clicked
  // if the pay button has been clicked
}

void TSideMenu_render(TSideMenu * SM, SDL_Renderer * R) {
  // Render background
  SDL_Rect dst;
  dst.x = 0;
  dst.y = 0;
  dst.w = 300;
  dst.h = 600;
  SDL_RenderCopy(R, SM->background, NULL, &dst);

  // Render all cards
  TCardMano_render(SM->cartas, SM->cartasCoords, R);
  // Render selected card if any

  // Render Hero status

  // Render selected tile data

  // Render pay button
  SM->button->pos_y = WIN_HEIGHT - SM->button->height - 11;
  SM->button->pos_x = 150 - SM->button->width/2;
  TButton_render(SM->button, R);
}
