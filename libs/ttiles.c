#include <ttiles.h>

void TTiles_init(TTiles * T, SDL_Renderer * R, TEnemy * E) {
  int i;
  int r = rand() % 7;
  // Create a new Tile with a bunch of new spaces
  // Give them each necesary value
  // Create the seven spaces
  // NOTE: when i=0 we know it's about the center space of the tile
  TSpace * temp;
  TSpace * central;
  //for (i=1; i<NUM_SPACES; i++) {
  for (i=0; i<NUM_SPACES; i++) {
    TSpace * newSpace;
    newSpace = malloc(sizeof(TSpace));
    if (r == i) {
      TSpace_init(newSpace, R, E);
    } else {
      TSpace_init(newSpace, R, NULL);
    } 
    // put the new space in the tile
    T->spaces[i] = newSpace;
    // Now interconect between the new and the cnetral
    if (i == 0) {
      central = newSpace;
    } else if (i == 1) {
      central->spaces[0] = newSpace;
      newSpace->spaces[0] = central;
      // now, point to the new space
      temp = newSpace;
    } else {
      // for the following spaces, put them 
      central->spaces[i-1] = newSpace;
      // now interconect this one with the one created before
      newSpace->spaces[0] = temp;
      // temp->spaces[i+1] = newSpace;

      newSpace->spaces[1] = central;
      // now point to the just created
      temp = newSpace;
    }
  }
}

void TTiles_Render(TTiles * T, SDL_Renderer * S, TCoord * Tc[NUM_SPACES]) {
  int i;
  // Render each Tile using the current Space
  for (i=0; i<NUM_SPACES; i++) {
    //printf("i: %d\n", i);
    TSpace_render(T->spaces[i], Tc[i], S); 
  }
  //printf("\n\n");
}

void TTiles_handleEvent(TTiles * T, SDL_Event * e, TCoord * Tc[NUM_SPACES]) {
  int i;
  // Call each event of each space
  for (i=0; i<NUM_SPACES; i++) {
    // This might just say if it was indeed clicked and change its
    // sprite. So then this function should just return if either it was
    // clicked
    TSpace_handleEvent(T->spaces[i], e, Tc[i]);
      // In case it was indeed clicked, pass the space pointer (or integer id)
      // to show it's data in the details viewport
  }
}
