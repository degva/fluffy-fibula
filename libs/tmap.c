#include <tmap.h>

/*
void _putTile(TMap * M, SDL_Surface * S, int x, int y, int w, int h) {
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  dst.w = w;
  dst.h = h;
  SDL_BlitSurface(M->map_tile, NULL, S, &dst);
}
*/

void TMap_init(TMap * M) {
  // Create first tile
  // Attach it to the Map with these coordinates
}

void TMap_Render(TMap * M, SDL_Surface * S) {
  // Render each surface of each tile
  // Uses the coordinates to do this
}

void TMap_handleEvent(TMap * M, SDL_Event * e) {
  // Call each the handler of each tile
}
