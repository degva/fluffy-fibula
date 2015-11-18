#ifndef _TMENU_
#define _TMENU_

#include <tlibs.h>
#include <tbutton.h>
#define MENU_TOTAL_BUTTONS 3


enum MenuItems {
  START,
  CONTINUE,
  QUIT
};


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
TMenu * TMenu_new(TTF_Font * , SDL_Renderer *);
int TMenu_OnEvent(SDL_Event *, TMenu *);
void TMenu_OnRender(SDL_Renderer *, TMenu *);

#endif
