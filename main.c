#include <capp.h>

int main(int argc, char **argv) {
  CApp * app;
  app = (CApp *) malloc(sizeof(CApp));
  CApp_init(app);

  TMap * map;
  map = (TMap *) malloc(sizeof(TMap));
  TMap_init(map);

  Game_OnExecute(app, map);
  return 0;
}
