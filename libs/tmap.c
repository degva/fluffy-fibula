#include <tmap.h>

void TMap_init(TMap * M) {
  M->map_tile = SDL_LoadBMP("img/tile.bmp");
  if (M->map_tile == NULL) {
    printf("Couldn't load tile.bmp file");
    SDL_Quit();
  }
}
