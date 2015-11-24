#include <sidemenu.h>

TSideMenu * TSideMenu_new(TTF_Font * F, THeroe * hero, TCardMano * cartas, TMap * M, SDL_Renderer * R) {
  TSideMenu * sm;
  sm = (TSideMenu *) malloc(sizeof(TSideMenu));

  // Init background images of the menu
  SDL_Surface * surf;
  surf = IMG_Load("img/b-side.png");
  if (surf == NULL)
    printf("Card image was not loaded!!");
  sm->background = SDL_CreateTextureFromSurface( R, surf );
  SDL_FreeSurface(surf);

  sm->mapa = M;
  sm->cartas = cartas;
  sm->hero = hero;

  sm->button = malloc(sizeof(TButton));
  TButton_init(sm->button, F , "Pagar", R);
  // Render pay button
  sm->button->pos_y = WIN_HEIGHT - sm->button->height - 11;
  sm->button->pos_x = 150 - sm->button->width/2;


  sm->cartasCoords = malloc(sizeof(TLista));
  TLista_init(sm->cartasCoords);

  sm->selectedCard = NULL;
  sm->selectedSpace = NULL;

  sm->paid = false;

  int i, x, y;
  x = 11;
  y = 11;
  int j = 0;
  for (i = 0; i < 40; i++) {
    TCoord * coord;
    coord = malloc(sizeof(TCoord));
    coord->x = x + 32*i + i;
    coord->y = y + 32*j + j;
    if ((i+1) % 9 == 0) {
      j++;
    }

    TLista_insertar(sm->cartasCoords, coord);
  }
  return sm;
}

void TSideMenu_handleEvent(TSideMenu * SM, SDL_Event * E) {
  // if mouse is inside one of the cards
  TCardMano_handleEvent(SM->cartas, SM->cartasCoords, E, &SM->selectedCard);
  // if the pay button has been clicked
  // handle pay button
  SM->button->pos_x = WIN_WIDTH - 200 + SM->button->width/2;
  TButton_handleEvent(SM->button, E);
  SM->button->pos_x = 150 - SM->button->width/2;
  
  // if it was clicked, then set paid to true
  if (SM->button->currentSprite == BUTTON_SPRITE_MOUSE_DOWN) {
    SM->paid = true;
  }
}

void _TSideMenu_priv_render(SDL_Renderer * R, SDL_Texture * T, SDL_Rect * r, SDL_Surface * S) {
  T = SDL_CreateTextureFromSurface(R, S);
  SDL_RenderCopy(R, T, NULL, r);
  SDL_DestroyTexture(T);
  SDL_FreeSurface(S);

}

void TSideMenu_render(TSideMenu * SM, TTF_Font * F, SDL_Renderer * R) {
  // Color white for the text
  SDL_Color color0 = {255,255,255};
  SDL_Surface * textSurface;
  SDL_Texture * textTexture;
  // Render background
  SDL_Rect dst;
  dst.x = 0;
  dst.y = 0;
  dst.w = 300;
  dst.h = 600;
  SDL_RenderCopy(R, SM->background, NULL, &dst);

  // Render all cards
  TCardMano_render(SM->cartas, SM->cartasCoords, R);
  // Render selected card if any
  if (SM->selectedCard != NULL) {

    char puntos[2];
    sprintf(puntos, "%d", SM->selectedCard->points);

    dst.y = 170;
    dst.x = 10;
    textSurface = TTF_RenderText_Solid(F, SM->selectedCard->name, color0);
    dst.w = textSurface->w;
    dst.h = textSurface->h;
    _TSideMenu_priv_render(R, textTexture, &dst, textSurface);

    textSurface = TTF_RenderText_Solid(F, puntos, color0);
    dst.x += dst.w + 10;
    dst.w = textSurface->w;
    _TSideMenu_priv_render(R, textTexture, &dst, textSurface);
    // render selected card data
  }

  // Render Hero status
  THeroe * hero = SM->hero;
  textSurface = TTF_RenderText_Solid(F, hero->name, color0);
  dst.y = 280;
  dst.x = 10;
  dst.w = textSurface->w;
  dst.h = textSurface->h;
  _TSideMenu_priv_render(R, textTexture, &dst, textSurface);

  char def[6], exp[6], niv[6];
  sprintf(niv, "Lvl: %d", hero->nivel);
  sprintf(exp, "Exp: %d", hero->exp);
  sprintf(def, "Def: %d", hero->def);

  char herStats[20];
  sprintf(herStats, "%s %s %s", niv, exp, def);

  textSurface = TTF_RenderText_Solid(F, herStats, color0);
  dst.x += 10;
  dst.y += dst.h + 10;
  dst.w = textSurface->w;
  _TSideMenu_priv_render(R, textTexture, &dst, textSurface);

  // Render selected space data if any
  int cT = SM->mapa->currTile;
  int cS = SM->mapa->currSpace;
  SM->selectedSpace =  ((TTiles *) SM->mapa->tiles[cT])->spaces[cS];
  if (SM->selectedSpace != NULL) {
    SDL_Rect dst2;
    dst2.y = 170 + 12 + 10;
    dst2.x = 10;
    // render selected space
    int tipo = ((TSpace *) SM->selectedSpace)->tipoDeSpace;
    char puntos[2];
    sprintf(puntos, "%d", tipo);

    char * message;
    switch (tipo) {
      case PLAIN:
        message = "Tipo Plano";
        break;
      case FOREST:
        message = "Tipo Bosque";
        break;
      case HILL:
        message = "Tipo Montanas";
        break;
      case SWAMP:
        message = "Tipo Lagos";
        break;
      default:
        message = "Tipo Inalcanzable";
        break;
    }
    textSurface = TTF_RenderText_Solid(F, message, color0);
    dst2.w = textSurface->w;
    dst2.h = textSurface->h;
    _TSideMenu_priv_render(R, textTexture, &dst2, textSurface);

    textSurface = TTF_RenderText_Solid(F, puntos, color0);
    dst2.x += dst2.w + 10;
    dst2.w = textSurface->w;
    _TSideMenu_priv_render(R, textTexture, &dst2, textSurface);

    // Render enemy if any
    if (SM->selectedSpace->enemy != NULL) {
      dst2.x = 10;
      dst2.y += dst2.h + 10;
      TEnemy * enemy = SM->selectedSpace->enemy;

      textSurface = TTF_RenderText_Solid(F, enemy->name, color0);
      dst2.w = textSurface->w;
      dst2.h = textSurface->h;
      _TSideMenu_priv_render(R, textTexture, &dst2, textSurface);
      char at[4], def[4], exp[4];
      sprintf(at, "A: %d", enemy->ataque);
      sprintf(def, "D: %d", enemy->defensa);
      sprintf(exp, "E: %d", enemy->experiencia);

      char wholeMess[14];
      sprintf(wholeMess, "%s %s %s", at, def, exp);

      dst2.x += 10;
      dst2.y += dst2.h + 10;
      
      textSurface = TTF_RenderText_Solid(F, wholeMess, color0);
      dst2.w = textSurface->w;
      dst2.h = textSurface->h;
      _TSideMenu_priv_render(R, textTexture, &dst2, textSurface);
    }
  }

  TButton_render(SM->button, R);
}

void TSideMenu_popTheHand(TSideMenu * M) {
  TCardMano_sendToDiscard(M->cartas, M->selectedCard);  
  TCardMano_takeFromAction(M->cartas, 1);
}
