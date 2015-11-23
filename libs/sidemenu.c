#include <sidemenu.h>

TSideMenu * TSideMenu_new(TTF_Font * F, THeroe * hero, TCardMano * cartas, TMap * M, SDL_Renderer * R) {
  TSideMenu * sm;
  sm = (TSideMenu *) malloc(sizeof(TSideMenu));
  
  // Init background images of the menu
  
  sm->mapa = M;
  sm->cartas = cartas;
  sm->hero = hero;
  sm->button = malloc(sizeof(TButton));
  sm->button = TButton_init(sm->button, F , "Pagar", R);

  // TODO Create the cartasCoords dinamically. Only need to do it once!
}

void TSideMenu_handleEvent(TSideMenu * SM, SDL_Event * E) {
  // if mouse is inside one of the cards
  // -- check if it has been clicked
  // if the pay button has been clicked
}

void TSideMenu_render(TSideMenu * SM, SDL_Renderer * R) {
  // Render all cards
  // Render selected card if any
  // Render Hero status
  // Render selected tile data
  // Render pay button
}

