#include <sidemenu.h>

TSideMenu * TSideMenu_new(TTF_Font * F, THeroe * hero, TCardMano * cartas, TMap * M, SDL_Renderer * R) {
  TSideMenu * sm;
  sm = (TSideMenu *) malloc(sizeof(TSideMenu));

  // Init background images of the menu

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
  for (i = 0; i < 40; i++) {
    TCoord * coord;
    coord = malloc(sizeof(TCoord));
    coord->x = x + 32*i + i;
    coord->y = y + 32*i + i;

    TLista_insertar(sm->cartasCoords, coord);
  }
}

void TSideMenu_handleEvent(TSideMenu * SM, SDL_Event * E) {
  // if mouse is inside one of the cards
  // -- check if it has been clicked
  // if the pay button has been clicked
}

void TSideMenu_render(TSideMenu * SM, SDL_Renderer * R) {
  // Render all cards
  TCardMano_render(SM->cartas, SM->cartasCoords);
  // Render selected card if any
  // Render Hero status
  // Render selected tile data
  // Render pay button
  SM->button->pos_y = WIN_HEIGHT - SM->button->height - 11;
  SM->button->pos_x = WIN_WIDTH + 11;
  TButton_render(SM->button, R);
}
