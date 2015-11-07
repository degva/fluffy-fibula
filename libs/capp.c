#include <capp.h>

/* Map Things */
void _putTile(TMap * M, CApp * C, int x, int y, int w, int h) {
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  dst.w = w;
  dst.h = h;
  SDL_BlitSurface(M->map_tile, NULL, C->appSurface, &dst);
  SDL_UpdateWindowSurface( C->appWindow );
}

void TMap_Render(TMap * M, CApp * C) {
  _putTile(M,C,10,10,15,15);
  _putTile(M,C,10,25,15,15);
  _putTile(M,C,25,10,15,15);
  _putTile(M,C,25,25,15,15);
}

/* Game related functions */
void CApp_init(CApp * C) {
  C->Running = true;
  C->appWindow = NULL;
}

void Game_OnRender(CApp * C, TMap * M) {
  TMap_Render(M,C);
}

int Game_OnExecute(CApp * C, TMap * M) {
  if (!Game_OnInit(C)) {
    return -1;
  }

  SDL_Event Event;
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
    "SDL2 Tutorial",
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

