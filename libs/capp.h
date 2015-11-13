#ifndef _CAPP_H_
#define _CAPP_H_

#include <tmap.h>

typedef struct {
  bool Running;
  SDL_Window* appWindow;
  SDL_Renderer* appRenderer;
  // SDL_Surface* appSurface; Deprecated
  TTF_Font * font;
} CApp;

CApp * CApp_new();

// Game Related functions

bool Game_OnInit(CApp * C);
int Game_OnExecute(CApp * C);
void Game_OnEvent(CApp * C, TMap * M, SDL_Event * Event);
void Game_OnLoop(CApp * C);
void Game_OnRender(CApp * C, TMap * map);
void Game_OnCleanup();

#endif
