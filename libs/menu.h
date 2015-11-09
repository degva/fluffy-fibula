#ifndef _TMENU_
#define _TMENU_

#include <tlibs.h>
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 20
#define MENU_TOTAL_BUTTONS 3

enum LButtonSprite {
  BUTTON_SPRITE_MOUSE_OUT,
  BUTTON_SPRITE_MOUSE_OVER_MOTION,
  BUTTON_SPRITE_MOUSE_DOWN,
  BUTTON_SPRITE_MOUSE_UP,
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
  int currentSprite;
  char * text;
  SDL_Surface * buttonText;
} TButton;

void TButton_init(TButton *, char *);
//void TButton_loadText(TButton *, char*);
void TButton_setPosition(TButton *, int x, int y);
void TButton_handleEvent(TButton *, SDL_Event* e);
void TButton_render(TButton *, TTF_Font *, SDL_Surface *);

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
  SDL_Surface * background;
  SDL_Surface * logo;
  bool Running;
} TMenu;

// Menu Functions
void TMenu_init(TMenu *);
int TMenu_OnEvent(SDL_Event *, TMenu *);
void TMenu_OnRender(SDL_Surface *, TTF_Font *, TMenu *);

#endif
