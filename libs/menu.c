#include <menu.h>


// Menu Functions
TMenu * TMenu_new(TTF_Font * F, SDL_Renderer * R) {
  TMenu * M;
  M = (TMenu *) malloc(sizeof(TMenu));
  // Iniciamos 3 botons primarios del menu
  // Init 3 primary buttons of the menu
  M->Running = true;
  M->buttons = malloc(sizeof(TButton *) * 3);

  TButton * bIniciar = malloc(sizeof(TButton));
  TButton * bContinuar = malloc(sizeof(TButton));
  TButton * bSalir = malloc(sizeof(TButton));

  TButton_init(bIniciar, F, "Iniciar", R);
  *(M->buttons) = bIniciar;
  TButton_init(bContinuar, F, "Continuar", R);
  *(M->buttons+1) = bContinuar;
  TButton_init(bSalir, F ,"Salir", R);
  *(M->buttons+2) = bSalir;

  TButton_setPosition(*(M->buttons), VP1_W/2, 100);
  TButton_setPosition(*(M->buttons+1), VP1_W/2, 150);
  TButton_setPosition(*(M->buttons+2), VP1_W/2, 200);

  // Init background images of the menu
  /* TODO load png backgrounds and such...
  M->background = SDL_LoadBMP( "img/background.bmp" );
  M->logo = SDL_LoadBMP( "img/logo.bmp" );
  */

  // TODO handle errors in case the images doesn't load correctly
  return M;
}

int TMenu_OnEvent(SDL_Event * e, TMenu * M) {
  // handle the three buttons
  int i, response;
  response = -1;
  for (i=0; i<MENU_TOTAL_BUTTONS; i++) {
    TButton_handleEvent(*(M->buttons+i), e);
    if ( ((TButton *) *(M->buttons+i))->currentSprite == BUTTON_SPRITE_MOUSE_DOWN ) {
      switch (i) {
        case START:
          response = START;
          break;
        case QUIT:
          response = QUIT;
          break;
      }
    }
  }
  if (e->type == SDL_QUIT) {
    response = QUIT;
  }
  return response;
}

void TMenu_OnRender(SDL_Renderer * R, TMenu * M) {
  int i;
  // Print the background:
  //SDL_RenderCopy( M->background, R, NULL, NULL);
  // Show the logo
  //SDL_RenderCopy( M->logo, R, NULL, NULL);

  // Show the texts
  for (i=0; i<MENU_TOTAL_BUTTONS; i++) {
    TButton_render( *(M->buttons+i), R);
  }
}
