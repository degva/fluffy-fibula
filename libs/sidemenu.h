#ifndef _SIDE_MENU_
#define _SIDE_MENU_

#include <tlibs.h>
#include <tbutton.h>
#include <tmap.h>
// #include <theroe.h>
// #include <tentstr.h>
// #include <tmano.h>

typedef struct {
  int currentCard;
  TButton * pay;
  SDL_Texture * background;
  TMap * mapa;      // pointer to the map
  // THand * cartas;   // pointer to the hands
  // TEnemy * enemies; // pointer to the enemies
  // THero * hero; // pointer to the hero
} TSideMenu;

TSideMenu * TSideMenu_new(TMap *); //,THand *);
// TSideMenu * TSideMenu_new(TMap *, THand *, TEnemy *, THero *);
void TSideMenu_handleEvent(TSideMenu *, SDL_Event *);
void TSideMenu_render(TSideMenu *, SDL_Renderer *);

#endif
