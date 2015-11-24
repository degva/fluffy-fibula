#ifndef _SIDE_MENU_
#define _SIDE_MENU_

#include <tlibs.h>
#include <tbutton.h>
#include <tmap.h>
#include <theroe.h>
#include <tentstr.h>
#include <mano.h>

typedef struct {
  TButton * button;
  SDL_Texture * background;
  TMap * mapa;      // pointer to the map
  TCardMano * cartas;   // pointer to the hands
  THeroe * hero; // pointer to the hero
  TLista * cartasCoords;
} TSideMenu;

TSideMenu * TSideMenu_new(TTF_Font *, THeroe *, TCardMano *, TMap *, SDL_Renderer * R); //,THand *);
// TSideMenu * TSideMenu_new(TMap *, THand *, TEnemy *, THero *);
void TSideMenu_handleEvent(TSideMenu *, SDL_Event *);
void TSideMenu_render(TSideMenu *, SDL_Renderer *);

#endif
