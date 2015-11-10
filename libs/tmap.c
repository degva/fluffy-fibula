#include <tmap.h>

void TMap_init(TMap * M) {
  // Set current Tile
  M->currentTile = 0;
  // Attach it to the Map with the coordinates of the middle of the screen
  TMap_putNewTileCoords(M, WIN_WIDTH/2, WIN_HEIGHT/2);
}

void TMap_putNewTileCoords(TMap * M, int posx, int posy) {
  int curTile = M->currentTile;
  
  // Create tile
  TTiles * tile;
  tile = malloc(sizeof(TTiles));
  TTiles_init(tile);
  
  // this is the first tile ( the one in the center )
  M->tiles[curTile] = tile;
  // put their coords
  // SPACE 0
  TCoord * coorT0 = malloc(sizeof(TCoord));
  coorT0->x = posx;
  coorT0->y = posy;
  // SPACE 1
  TCoord * coorT1 = malloc(sizeof(TCoord));
  coorT1->x = posx + SPACESIZE/2;
  coorT1->y = posy + 0.8*SPACESIZE;
  // SPACE 2
  TCoord * coorT2 = malloc(sizeof(TCoord));
  coorT2->x = posx + SPACESIZE;
  coorT2->y = posy;
  // SPACE 3
  TCoord * coorT3 = malloc(sizeof(TCoord));
  coorT3->x = posx + SPACESIZE/2;
  coorT3->y = posy - 0.8*SPACESIZE;
  // SPACE 4
  TCoord * coorT4 = malloc(sizeof(TCoord));
  coorT4->x = posx - SPACESIZE/2;
  coorT4->y = posy - 0.8*SPACESIZE;
  // SPACE 5
  TCoord * coorT5 = malloc(sizeof(TCoord));
  coorT5->x = posx - SPACESIZE;
  coorT5->y = posy;
  // SPACE 6
  TCoord * coorT6 = malloc(sizeof(TCoord));
  coorT6->x = posx - SPACESIZE/2;
  coorT6->y = posy + 0.8*SPACESIZE;

  // put Coordinates on the tiles
  M->coords[curTile][0] = coorT0;
  M->coords[curTile][1] = coorT1;
  M->coords[curTile][2] = coorT2;
  M->coords[curTile][3] = coorT3;
  M->coords[curTile][4] = coorT4;
  M->coords[curTile][5] = coorT5;
  M->coords[curTile][6] = coorT6;

  // Put the tile in the current tposition
  M->currentTile += 1;
}

void TMap_addNewTile(TMap * M, int pos) {
  int posx = ((TCoord *) M->tiles[M->currentTile])->x;
  int posy = ((TCoord *) M->tiles[M->currentTile])->y;
  int des = 1.2438;
  switch (pos) {
    case NOR_EAST:
      TMap_putNewTileCoords(M, posx + 2*SPACESIZE, posy + 2*des*SPACESIZE);
      break;
    case EAST:
      TMap_putNewTileCoords(M, posx + 2*SPACESIZE, posy - 2*des*SPACESIZE);
      break;
    case SOUTH:
      TMap_putNewTileCoords(M, posx + SPACESIZE/2, posy - 3*des*SPACESIZE);
      break;
    case SOU_WEST:
      TMap_putNewTileCoords(M, posx - 2*SPACESIZE, posy - 2*des*SPACESIZE);
      break;
    case WEST:
      TMap_putNewTileCoords(M, posx - 2*SPACESIZE, posy + 2*des*SPACESIZE);
      break;
    case NORTH:
      TMap_putNewTileCoords(M, posx - SPACESIZE/2, posy + 3*des*SPACESIZE);
      break;
  }
}

void TMap_Render(TMap * M, SDL_Surface * S) {
  int i;
  // Render each surface of each tile
  // Uses the coordinates to do this
  for (i=0; i<NUMBER_OF_TILES; i++) {
    if (M->tiles[i] == NULL) {
      break;
    }
    TTiles_Render(M->tiles[i], S, M->coords[i]);
  }
}

void TMap_handleEvent(TMap * M, SDL_Event * e) {
  int i;
  // Call each the handler of each tile
  // uses the coordinates to do this
  for (i=0; i<NUMBER_OF_TILES; i++) {
    TTiles_handleEvent(M->tiles[i], e, M->coords[i]);
  }
}
