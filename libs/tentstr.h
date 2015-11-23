#ifndef _T_ENT_STRUCS_
#define _T_ENT_STRUCS_

#include <tlibs.h>
#include <tlist.h>

// Type Enemies
typedef struct {
  char * name;
  int ataque;
  int defensa;
  int experiencia;
  SDL_Texture * texture;
} TEnemy;

TEnemy * TEnemy_new(SDL_Renderer *);
TLista * TEnemy_createEnemies(int);
void TEnemy_render(TEnemy *, TCoord *, SDL_Renderer *);

// Friend Structure
typedef struct {
  char * name;
  // TList * cards;
  // TList * price;
} TFriendStruc;

#endif
