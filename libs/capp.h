#ifndef _CAPP_H_
#define _CAPP_H_

#include <tmap.h>
#include <menu.h>
// #include <sidemenu.h>
// #include <mano.h>
// #include <tentstr.h>

typedef struct {
  bool Running;
  SDL_Window* appWindow;
  SDL_Renderer* appRenderer;
  TTF_Font * font;

  // Game variables
  TMenu * menu;
  TMap * map;
  THeroe * heroe;
  TSideMenu * sidemenu;
  TLista * mano;
  TLista * entities;
} CApp;

CApp * CApp_new();

// Game Related functions

bool Game_OnInit(CApp * C);
int Game_OnExecute(CApp * C);
void Game_OnEvent(CApp * C, SDL_Event * Event);
void Game_OnLoop(CApp * C);
void Game_OnRender(CApp * C);
void Game_OnCleanup();

#endif
