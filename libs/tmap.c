#include <tmap.h>

/* Map Things */
void _putTile(TMap * M, SDL_Surface * S, int x, int y, int w, int h) {
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  dst.w = w;
  dst.h = h;
  SDL_BlitSurface(M->map_tile, NULL, S, &dst);
  //SDL_UpdateWindowSurface( C->appWindow );
}

void TMap_init(TMap * M) {
  M->map_tile = SDL_LoadBMP("img/tile.bmp");
  if (M->map_tile == NULL) {
    printf("Couldn't load tile.bmp file");
    SDL_Quit();
  }
}

void TMap_Render(TMap * M, SDL_Surface * S) {
  _putTile(M,S,10,10,15,15);
  _putTile(M,S,10,25,15,15);
  _putTile(M,S,25,10,15,15);
  _putTile(M,S,25,25,15,15);
}
