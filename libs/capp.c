#include <capp.h>

/* Game related functions */
void CApp_init(CApp * C) {
  C->Running = true;
  C->appWindow = NULL;
}

void Game_OnRender(CApp * C, TMap * M) {
  TMap_Render(M,C->appSurface);
  SDL_UpdateWindowSurface( C->appWindow );
}

int Game_OnExecute(CApp * C, TMap * M) {
  if (!Game_OnInit(C)) {
    return -1;
  }
  // Create Event and Menu
  TMenu * menu;
  menu = (TMenu *) malloc(sizeof(TMenu));
  TMenu_init(menu);
  SDL_Event Event;
  // Show Menu
  while(C->Running) {
    while(SDL_PollEvent(&Event)) {
      TMenu_OnEvent(&Event, menu);
      // loop for buttons:http://www.lazyfoo.net/tutorials/SDL/17_mouse_events/index.php
    }
    TMenu_OnRender(C->appSurface, C->font, menu);
    // Show new graphs
    SDL_UpdateWindowSurface( C->appWindow );
  }
  // Show Game
  while(C->Running) {
    while(SDL_PollEvent(&Event)) {
      Game_OnEvent(C, &Event);
    }
    //Game_OnLoop(C);
    Game_OnRender(C, M);
  }
  return 0;
}

bool Game_OnInit(CApp * C) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }

  C->appWindow = SDL_CreateWindow(
    "Cualquier cosa",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640, 480,
    SDL_WINDOW_SHOWN
  );
  if (C->appWindow == NULL) {
    return false;
  }

  C->appSurface = SDL_GetWindowSurface(C->appWindow);
  if (C->appSurface == NULL) {
    return false;
  }
  
  // Init font things
  if (TTF_Init() < 0) {
    return false;
  }

  // load Hack font
  C->font = TTF_OpenFont("fonts/Hack.ttf", 16);
  if (!C->font) {
    printf("Couldn't load Hack font, %s\n", TTF_GetError());
    TTF_Quit();
    return false;
  }
  return true;
}

void Game_OnCleanup() {
  SDL_Quit();
}

void Game_OnEvent(CApp * C, SDL_Event * Event) {
  if (Event->type == SDL_QUIT) {
    C->Running = false;
  }
}

