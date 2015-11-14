#ifndef _TMENU_
#define _TMENU_

#include <tlibs.h>
/*
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 20
*/
#define MENU_TOTAL_BUTTONS 3

enum LButtonSprite {
  BUTTON_SPRITE_MOUSE_OUT,
  BUTTON_SPRITE_MOUSE_OVER_MOTION,
  BUTTON_SPRITE_MOUSE_DOWN,
  BUTTON_SPRITE_TOTAL
};

enum MenuItems {
  START,
  CONTINUE,
  QUIT
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

/* El menu consiste de un grupo de botones
 * y fondos. Entonces, usaremos 2 botones para
 * el menu:
 *  - Iniciar
 *  - Continuar
 *  - Salir
 *
 *  Ademas, tiene fondos e imagenes
 *  - Fondo
 *  - Logo
 */

typedef struct {
  TButton **buttons;
  SDL_Texture * background;
  SDL_Texture * logo;
  bool Running;
} TMenu;

// Menu Functions
void TMenu_init(TMenu *, TTF_Font * , SDL_Renderer *);
int TMenu_OnEvent(SDL_Event *, TMenu *);
void TMenu_OnRender(SDL_Renderer *, TMenu *);

#endif
