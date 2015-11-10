#include <capp.h>
#include <menu.h>

/* Game related functions */
void CApp_init(CApp * C) {
  C->Running = true;
  C->appWindow = NULL;
}

void Game_OnRender(CApp * C, TMap * M) {
  TMap_Render(M,C->appSurface);
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
  while(menu->Running && C->Running) {
    while(SDL_PollEvent(&Event)) {
      switch (TMenu_OnEvent(&Event, menu)) {
        case START:
          menu->Running = false;
          break;
        case QUIT:
          C->Running = false;
          break;
      }
    }
    TMenu_OnRender(C->appSurface, C->font, menu);
    // Show new graphs
    SDL_UpdateWindowSurface( C->appWindow );
    // Clear the screen
    SDL_FillRect(C->appSurface,NULL,0);
  }
  // Show Game
  while(C->Running) {
    while(SDL_PollEvent(&Event)) {
      Game_OnEvent(C, &Event);
    }
    //Game_OnLoop(C);
    Game_OnRender(C, M);
    SDL_UpdateWindowSurface( C->appWindow );
    // Clear the screen
    SDL_FillRect(C->appSurface,NULL,0);
  }
  return 0;
}

bool Game_OnInit(CApp * C) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return false;
  }
  
  // Init font things
  if (TTF_Init() < 0) {
    SDL_Quit();
    return false;
  }

  C->appWindow = SDL_CreateWindow(
    "Cualquier cosa",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WIN_WIDTH, WIN_HEIGHT,
    SDL_WINDOW_SHOWN
  );
  if (C->appWindow == NULL) {
    SDL_Quit();
    TTF_Quit();
    return false;
  }

  C->appSurface = SDL_GetWindowSurface(C->appWindow);
  if (C->appSurface == NULL) {
    SDL_Quit();
    TTF_Quit();
    return false;
  }

  // load Hack font
  C->font = TTF_OpenFont("fonts/Hack.ttf", 16);
  if (C->font == NULL) {
    printf("Couldn't load Hack font, %s\n", TTF_GetError());
    SDL_Quit();
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

