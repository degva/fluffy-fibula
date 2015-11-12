#include <capp.h>

int main(int argc, char **argv) {
  CApp * app;
  app = CApp_new();

  TMap * map;
  map = (TMap *) malloc(sizeof(TMap));
  TMap_init(map, app->appRenderer);

  Game_OnExecute(app, map);
  return 0;
}
