#include <capp.h>

int main(int argc, char **argv) {
  CApp * app;
  app = CApp_new();

  Game_OnExecute(app);
  return 0;
}
