#include <capp.h>
#include <menu.h>

/* Game related functions */
CApp * CApp_new() {
  CApp * app;
  app = (CApp *) malloc(sizeof(CApp));
  app->Running = true;
  app->appWindow = NULL;
  app->appRenderer = NULL;
  return app;
}

void Game_OnRender(CApp * C, TMap * M) {
  TMap_Render(M,C->appRenderer);
}

int Game_OnExecute(CApp * C) {
  if (!Game_OnInit(C)) {
    return -1;
  }

  // Create Event and Menu
  TMenu * menu;
  menu = (TMenu *) malloc(sizeof(TMenu));
  TMenu_init(menu, C->font, C->appRenderer);
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

    TMenu_OnRender(C->appRenderer, menu);

    // Render Present
    SDL_RenderPresent( C->appRenderer );
    
    // Clear Renderer
    SDL_SetRenderDrawColor( C->appRenderer, 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderClear( C->appRenderer );
  }
  // Create the Map
  TMap * map;
  map = (TMap *) malloc(sizeof(TMap));
  TMap_init(map, C->appRenderer);
  // Show Game
  while(C->Running) {
    while(SDL_PollEvent(&Event)) {
      Game_OnEvent(C, map, &Event);
    }
    
    //Game_OnLoop(C);
    Game_OnRender(C, map);

    // Render Present
    SDL_RenderPresent( C->appRenderer );

    // Clear Renderer
    SDL_SetRenderDrawColor( C->appRenderer, 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderClear( C->appRenderer );
  }
  return 0;
}

bool Game_OnInit(CApp * C) {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("Could not init SDL\n");
    return false;
  }
 
  if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" )) {
    printf("Linear texture could not be enabled\n");
    SDL_Quit();
    return false;
  }

  // Init font things
  if (TTF_Init() < 0) {
    printf("Couldn't init TTF library");
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

  C->appRenderer = SDL_CreateRenderer( C->appWindow, -1, SDL_RENDERER_ACCELERATED );
  if (C->appRenderer == NULL) {
    printf("Could not create Renderer");
    SDL_Quit();
    TTF_Quit();
    return false;
  }

  /* Deprecated
  C->appSurface = SDL_GetWindowSurface(C->appWindow);
  if (C->appSurface == NULL) {
    SDL_Quit();
    TTF_Quit();
    return false;
  }
  */

  // load Hack font
  C->font = TTF_OpenFont("fonts/Hack.ttf", 16);
  if (C->font == NULL) {
    printf("Couldn't load Hack font, %s\n", TTF_GetError());
    SDL_Quit();
    TTF_Quit();
    return false;
  }

  SDL_SetRenderDrawColor( C->appRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
  // Start IMG things!
  if ( !( IMG_Init(IMG_INIT_PNG) ) ) {
    printf("Could not start PNG libs!");
    SDL_Quit();
    TTF_Quit();
    return false;
  }
  return true;
}

void Game_OnCleanup() {
  SDL_Quit();
}

void Game_OnEvent(CApp * C, TMap * M, SDL_Event * Event) {
  TMap_handleEvent(M, Event);
  if (Event->type == SDL_QUIT) {
    C->Running = false;
  }
}

