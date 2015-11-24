#include <capp.h>

/* Game related functions */
CApp * CApp_new() {
  CApp * app;
  app = (CApp *) malloc(sizeof(CApp));
  app->Running = true;
  app->appWindow = NULL;
  app->appRenderer = NULL;
  app->menu = NULL;
  app->map = NULL;
  app->level = 2;
  return app;
}

void Game_OnRender(CApp * C) {
  // Render the map
  SDL_Rect viewPort1;
  viewPort1.x = VP1_X;
  viewPort1.y = VP1_Y;
  viewPort1.w = VP1_W;
  viewPort1.h = VP1_H;
  SDL_RenderSetViewport(C->appRenderer, &viewPort1);
  TMap_Render(C->map, C->appRenderer);

  // Render the side Menu
  SDL_Rect viewPort2;
  viewPort2.x = VP2_X;
  viewPort2.y = VP2_Y;
  viewPort2.w = VP2_W;
  viewPort2.h = VP2_H;
  SDL_RenderSetViewport(C->appRenderer, &viewPort2);
  TSideMenu_render(C->sidemenu, C->appRenderer);
}

int Game_OnExecute(CApp * C) {
  if (!Game_OnInit(C)) {
    return -1;
  }

  // Create Event and Menu
  C->menu = TMenu_new(C->font, C->appRenderer);
  SDL_Event Event;
  // Show Menu
  while(C->menu->Running && C->Running) {
    while(SDL_PollEvent(&Event)) {
      switch (TMenu_OnEvent(&Event, C->menu)) {
        case START:
          C->menu->Running = false;
          break;
        case QUIT:
          C->Running = false;
          break;
      }
    }

    TMenu_OnRender(C->appRenderer, C->menu);

    // Render Present
    SDL_RenderPresent( C->appRenderer );

    // Clear Renderer
    SDL_SetRenderDrawColor( C->appRenderer, 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderClear( C->appRenderer );
  }

  // Create the Map
  C->entities = TEnemy_createEnemies(8, C->appRenderer);
  C->map = TMap_new(C->appRenderer, C->entities);

  // Create the game variables
  C->heroe = THeroe_new(C->appRenderer);
  C->mano = TCardMano_new(C->appRenderer, C->level);

  C->sidemenu = TSideMenu_new(C->font, C->heroe, C->mano, C->map, C->appRenderer);

  // Show Game
  while(C->Running) {
    while(SDL_PollEvent(&Event)) {
      Game_OnEvent(C, &Event);
    }

    Game_OnRender(C);

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

void Game_OnEvent(CApp * C, SDL_Event * Event) {
  TMap_handleEvent(C->map, Event);
  TSideMenu_handleEvent(C->sidemenu, Event);
  if (Event->type == SDL_QUIT) {
    C->Running = false;
  }
}
