#ifndef _TBUTTONS_
#define _TBUTTONS_

#include <tlibs.h>

enum LButtonSprite {
  BUTTON_SPRITE_MOUSE_OUT,
  BUTTON_SPRITE_MOUSE_OVER_MOTION,
  BUTTON_SPRITE_MOUSE_DOWN,
  BUTTON_SPRITE_TOTAL
};

// Button things...
typedef struct {
  int pos_x;
  int pos_y;
  int width;
  int height;
  int currentSprite;
  char * text;
  SDL_Texture *buttonText[BUTTON_SPRITE_TOTAL];
  // SDL_Surface * buttonText; Deprecated
} TButton;

void TButton_init(TButton *, TTF_Font * , char *, SDL_Renderer * R);
//void TButton_loadText(TButton *, char*);
void TButton_setPosition(TButton *, int x, int y);
void TButton_handleEvent(TButton *, SDL_Event* e);
void TButton_render(TButton *, SDL_Renderer *);
#endif


