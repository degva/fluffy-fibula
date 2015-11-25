#include <tbutton.h>

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
