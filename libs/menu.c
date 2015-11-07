#include <menu.h>

/* Button functions */

/* Inits a function */
void TButton_init(TButton * B) {
  B->pos_x = 0;
  B->pos_y = 0;
  B->currentSprite = BUTTON_SPRITE_MOUSE_OUT;
  B->buttonText = NULL;
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
