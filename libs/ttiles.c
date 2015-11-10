#include <ttiles.h>

void TTiles_init(TTiles * T) {
  int i;
  // Create a new Tile with a bunch of new spaces
  // Give them each necesary value
  // Create the seven spaces
  // NOTE: when i=0 we know it's about the center space of the tile
  TSpace * temp;
  TSpace * central = malloc(sizeof(TSpace));
  TSpace_init(central);
  T->spaces[0] = central;

  for (i=1; i<NUM_SPACES; i++) {
    TSpace * newSpace;
    newSpace = malloc(sizeof(TSpace));
    TSpace_init(newSpace);
    // put the new space in the tile
    T->spaces[i] = newSpace;
    // Now interconect between the new and the cnetral
    if (i == 1)
      central->spaces[0] = newSpace;
      newSpace->spaces[0] = central;
      // now, point to the new space
      temp = newSpace;
    else {
      // for the following spaces, put them 
      central->spaces[i] = newSpace;
      // now interconect this one with the one created before
      newSpace->spaces[0] = temp;
      temp->spaces[1] = newSpace;
      // now point to the just created
      temp = newSpace;
    }
  }
}

void TTiles_Render(TTiles * T, TCoord * Tc[NUM_SPACES], SDL_Surface * S) {
  int i;
  // Render each Tile using the current Space
  for (i=0; i<NUM_SPACES; i++) {
    TSpace_Render(T->spaces[i], Tc[i], S); 
  }
}

void TTiles_handleEvent(TTiles * T, SDL_Event * e, TCoord * Tc[NUM_SPACES]) {
  int i;
  // Call each event of each space
  for (i=0; i<NUM_SPACES; i++) {
    // This might just say if it was indeed clicked and change its
    // sprite. So then this function should just return if either it was
    // clicked
    if ( TSpace_handleEvent(T->spaces[i], e, Tc[i]) ) {
      // In case it was indeed clicked, pass the space pointer (or integer id)
      // to show it's data in the details viewport
    }
  }
}
