#include <menu.h>

/* Button functions */

/* Inits a function */
void TButton_init(TButton * B, TTF_Font * F, char * text, SDL_Renderer * R) {
  B->text = text;
  B->pos_x = 0;
  B->pos_y = 0;
  B->currentSprite = BUTTON_SPRITE_MOUSE_OUT;

  // Some Colors...
  SDL_Color color0 = {255,255,255};
  SDL_Color color1 = {0,255,0};
  SDL_Color color2 = {255,0,0};
  /*
   * NOte: it's possible to get the text dimensions with:
   * textSurface->w
   * textSurface->h
   */

  SDL_Surface * textSurface;
  textSurface = TTF_RenderText_Solid(F, B->text, color0);
  B->buttonText[BUTTON_SPRITE_MOUSE_OUT] = SDL_CreateTextureFromSurface(R, textSurface);

  textSurface = TTF_RenderText_Solid(F, B->text, color1);
  B->buttonText[BUTTON_SPRITE_MOUSE_OVER_MOTION] = SDL_CreateTextureFromSurface(R, textSurface);

  textSurface = TTF_RenderText_Solid(F, B->text, color2);
  B->buttonText[BUTTON_SPRITE_MOUSE_DOWN] = SDL_CreateTextureFromSurface(R, textSurface);

  B->width = textSurface->w;
  B->height = textSurface->h;
  SDL_FreeSurface(textSurface);
}

void TButton_setPosition(TButton * B, int x, int y) {
  B->pos_x = x;
  B->pos_y = y;
}

void TButton_handleEvent(TButton * B, SDL_Event * e) {
  if (
    e->type == SDL_MOUSEMOTION
    || e->type == SDL_MOUSEBUTTONDOWN
  ) {
    // Get mouse position
    int x, y;
    SDL_GetMouseState( &x, &y );
    // Check if mouse is in button
    bool inside = true;
    // Mouse if left of the button
    if (x < B->pos_x) {
      inside = false;
    // mose is right of the button
    } else if (x > B->pos_x + B->width) {
      inside = false;
    // mouse is above the button
    } else if (y < B->pos_y) {
      inside = false;
    } else if (y > B->pos_y + B->height) {
      inside = false;
    }

    // Mouse is outside button
    if (!inside) {
      B->currentSprite = BUTTON_SPRITE_MOUSE_OUT;
    }
    // Mouse is inside button
    else {
      switch (e->type) {
        case SDL_MOUSEMOTION:
          B->currentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
          break;
        case SDL_MOUSEBUTTONDOWN:
          B->currentSprite = BUTTON_SPRITE_MOUSE_DOWN;
          break;
      }
    }
  }
}

void TButton_render(TButton * B, SDL_Renderer * R) {
  // Put it into the screen
  SDL_Rect destRect;
  destRect.x = B->pos_x;
  destRect.y = B->pos_y;
  destRect.w = B->width;;
  destRect.h = B->height;
  SDL_RenderCopy(R, B->buttonText[B->currentSprite], NULL, &destRect);
  // Free Texture!!
}

// Menu Functions
void TMenu_init(TMenu * M, TTF_Font * F, SDL_Renderer * R) {
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
