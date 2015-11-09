#ifndef _CAPP_H_
#define _CAPP_H_

#include <tmap.h>

typedef struct {
  bool Running;
  SDL_Window* appWindow;
  SDL_Surface* appSurface;
  TTF_Font * font;
} CApp;

void CApp_init(CApp * C);

// Game Related functions

bool Game_OnInit(CApp * C);
int Game_OnExecute(CApp * C, TMap * map);
void Game_OnEvent(CApp * C, SDL_Event * Event);
void Game_OnLoop(CApp * C);
void Game_OnRender(CApp * C, TMap * map);
void Game_OnCleanup();

#endif
