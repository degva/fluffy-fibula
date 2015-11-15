#ifndef _T_ENT_STRUCS_
#define _T_ENT_STRUCS_

#include <tlibs.h>
// #include <tmlists.h> for the friend structure

enum types {
  ENEMY_ENT,  // enemigo
  FRIEND_STR, // estructura amiga
  // ENEMY_STR,  // estructura enemiga
  ENT_TYPES_TOTAL
};

// Type Enemies
typedef struct {
  char * name;
  int ataque;
  int defensa;
  int experiencia;
  SDL_Texture * picture;
} TEnemy;

TEnemy * TEnemy_new(SDL_Renderer *);
void TEnemy_render(TEnemy *, TCoord *, SDL_Renderer *);

// Friend Structure
typedef struct {
  char * name;
  // TList * cards;
  // TList * price;
} TFriendStruc;

#endif
