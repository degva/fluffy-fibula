#include <menu.h>

/* Button functions */

/* Inits a function */
void TButton_init(TButton * B) {
  B->text = NULL;
  B->pos_x = 0;
  B->pos_y = 0;
  B->currentSprite = BUTTON_SPRITE_MOUSE_OUT;
  B->buttonText = NULL;
}

void TButton_loadText(TButton * B, char * text) {
  // Save text into the Button
  B->text = text;
}

void TButton_setPosition(TButton * B, int x, int y) {
  B->pos_x = x;
  B->pos_y = y;
}

void TButton_handleEvent(TButton * B, SDL_Event * e) {
  if (
    e->type == SDL_MOUSEMOTION
    || e->type == SDL_MOUSEBUTTONDOWN
    || e->type == SDL_MOUSEBUTTONUP
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
    } else if (x > B->pos_x + BUTTON_WIDTH) {
      inside = false;
    // mouse is above the button
    } else if (y < B->pos_y) {
      inside = false;
    } else if (y > B->pos_y + BUTTON_HEIGHT) {
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
        case SDL_MOUSEBUTTONUP:
          B->currentSprite = BUTTON_SPRITE_MOUSE_UP;
          break;
      }
    }
  }
}

void TButton_render(TButton * B, TTF_Font * F, SDL_Surface * S) {
  // Color if OUT
  SDL_Color color0 = {255,255,255};
  SDL_Color color1 = {0,255,0};
  SDL_Color color2 = {255,0,0};
  SDL_Color color3 = {0,0,255};
  switch (B->currentSprite) {
    case BUTTON_SPRITE_MOUSE_OUT:
      B->buttonText = TTF_RenderText_Solid(F, B->text, color0);
      break;
    case BUTTON_SPRITE_MOUSE_OVER_MOTION:
      B->buttonText = TTF_RenderText_Solid(F, B->text, color1);
      break;
    case BUTTON_SPRITE_MOUSE_DOWN:
      B->buttonText = TTF_RenderText_Solid(F, B->text, color2);
      break;
    case BUTTON_SPRITE_MOUSE_UP:
      B->buttonText = TTF_RenderText_Solid(F, B->text, color3);
      break;
  }
  // Create text surface
  //B->buttonText = TTF_RenderText_Solid(F, B->text, color);
  // Put it into the screen
  SDL_BlitSurface(B->buttonText, NULL, S, NULL);
  // Free Button Surface
  SDL_FreeSurface(B->buttonText);
}

// Menu Functions
void TMenu_init(TMenu * M) {
  // Iniciamos 3 botons primarios del menu
  // Init 3 primary buttons of the menu
  M->buttons = malloc(sizeof(TButton *) * MENU_TOTAL_BUTTONS);
  TButton_loadText(*(M->buttons), "Iniciar");
  TButton_loadText(*(M->buttons+1), "Continuar");
  TButton_loadText(*(M->buttons+2), "Salir");

  // Init background images of the menu
  M->background = SDL_LoadBMP( "img/background.bmp" );
  M->logo = SDL_LoadBMP( "img/logo.bmp" );

  // TODO handle errors in case the images doesn't load correctly
}

void TMenu_OnEvent(SDL_Event * e, TMenu * M) {
  // handle the three buttons
  int i;
  for (i=0; i<MENU_TOTAL_BUTTONS; i++) {
    TButton_handleEvent(*(M->buttons+i), e);
  }
}

void TMenu_OnRender(SDL_Surface * S, TTF_Font * F, TMenu * M) {
  int i;
  // Print the background:
  SDL_BlitSurface( M->background, NULL, S, NULL);
  // Show the logo
  SDL_BlitSurface( M->logo, NULL, S, NULL);

  // Show the texts
  for (i=0; i<MENU_TOTAL_BUTTONS; i++) {
    TButton_render( *(M->buttons+i), F, S);
  }
}
