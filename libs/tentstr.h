#ifndef _T_ENT_STRUCS_
#define _T_ENT_STRUCS_

#include <tlibs.h>
// #include <tmlists.h> for the friend structure

// Type Enemies

typedef struct _TEnemy TEnemy;
struct _TEnemy{
  char * name;
  int ataque;
  int defensa;
  int experiencia;
  SDL_Texture * picture;
};

TEnemy * TEnemy_new(SDL_Renderer *);
TArray * TEnemy_Create_Enemys(int);
void TEnemy_render(TEnemy *, TCoord *, SDL_Renderer *);

// Friend Structure
typedef struct {
  char * name;
  // TList * cards;
  // TList * price;
} TFriendStruc;

#endif
