#include <tentstr.h>

TEnemy * TEnemy_new(SDL_Renderer * R) {
  TEnemy * enemy;
  enemy = (TEnemy *) malloc(sizeof(TEnemy));

  enemy->name = "Enemigo";
  enemy->ataque = rand() % 19 + 2; // from 2 to 20 Points
  enemy->defensa = enemy->ataque * 0.8; // 80% of its atack
  enemy->experiencia = enemy->ataque % enemy->defensa;

  int r;
  r = rand() % 5 + 1; //from 1 to 5

  SDL_Surface * img;
  switch (r) {
    case 1:
      img = IMG_Load( "img/monster1.png" );
      break;
    case 2:
      img = IMG_Load( "img/monster1.png" );
      break;
    case 3:
      img = IMG_Load( "img/monster3.png" );
      break;
    case 4:
      img = IMG_Load( "img/monster4.png" );
      break;
    case 5:
      img = IMG_Load( "img/monster5.png" );
      break;
  }
  enemy->texture = SDL_CreateTextureFromSurface( R, img );

  return enemy;
}

TLista * TEnemy_createEnemies(int num, SDL_Renderer * R){
  TLista * enemies;
  TEnemy *enemy;
  int i ;
  enemies = malloc(sizeof(TLista));
  TLista_init(enemies);
  for (i=0;i<num;i++){
    enemy = TEnemy_new(R);
    TLista_insertar(enemies, enemy);
  }

  return enemies;
}


void TEnemy_render(TEnemy * Te, TCoord * C, SDL_Renderer * R) {
  SDL_Rect dst;
  dst.x = C->x + 16;
  dst.y = C->y + 16;
  dst.w = 32;
  dst.h = 32;

  SDL_RenderCopy(R, Te->texture, NULL, &dst);
}
