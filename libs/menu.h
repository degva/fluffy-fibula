#ifndef _TMENU_
#define _TMENU_

#include <capp.h>

const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 100;
const int TOTAL_BUTTONS = 4;

enum LButtonSprite {
  BUTTON_SPRITE_MOUSE_OUT,
  BUTTON_SPRITE_MOUSE_OVER_MOTION,
  BUTTON_SPRITE_MOUSE_DOWN,
  BUTTON_SPRITE_MOUSE_UP,
  BUTTON_SPRITE_TOTAL
}

// Button things...
typedef struct {
  int pos_x;
  int pos_y;
  int currentSprite;
  SDL_Surface * buttonText;
} TButton;

void TButton_init(TButton *);
void TButton_setPosition(TButton *, int x, int y);
void TButton_handleEvent(TButton *, SDL_Event* e);
void TButton_render(TButton *);

// Menu Functions
void Menu_OnEvent(CApp *);
void Menu_OnRender(CApp *);

#endif
