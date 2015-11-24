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
  TMap * mapa;          // pointer to the map
  TCardMano * cartas;   // pointer to the hands
  THeroe * hero;        // pointer to the hero
  TLista * cartasCoords;
  
  TCard * selectedCard; // pointer to the selected card to be renderer
  TSpace * selectedSpace;
} TSideMenu;

TSideMenu * TSideMenu_new(TTF_Font *, THeroe *, TCardMano *, TMap *, SDL_Renderer * R);
void TSideMenu_handleEvent(TSideMenu *, SDL_Event *);
void TSideMenu_render(TSideMenu *, TTF_Font * , SDL_Renderer *);

#endif
