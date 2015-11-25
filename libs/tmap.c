#include <tmap.h>

TMap * TMap_new(SDL_Renderer * R, TLista * E) {
  TMap * M;
  M = (TMap *) malloc(sizeof(TMap));
 
  // call the background
  SDL_Surface * surf;
  surf = IMG_Load("img/b-map.png");
  if (surf == NULL)
    printf("Card image was not loaded!!");
  M->background = SDL_CreateTextureFromSurface( R, surf );
  SDL_FreeSurface(surf);

  // Set current Tile and currentSpace
  M->currTile = 0;
  M->currSpace = 0;
  M->tileCount = 0;
  int i;
  for (i=0; i<NUMBER_OF_TILES; i++) {
    M->tiles[i] = NULL;
  }
  // Attach it to the Map with the coordinates of the middle of the screen

  M->actualTile = 0;
  M->actualSpace = 0;

  TMap_putNewTileCoords(M, VP1_W/2, VP1_H/2, R, TLista_pop(E)->elem);
  return M;
}

void TMap_putNewTileCoords(TMap * M, int posx, int posy, SDL_Renderer * R, TEnemy * E) {
  int currTile = M->tileCount;
  float goldNum = 0.76;
  // Create tile
  TTiles * tile;
  tile = malloc(sizeof(TTiles));
  TTiles_init(tile, R, E);

  // this is the first tile ( the one in the center )
  M->tiles[currTile] = tile;
  // put their coords
  // SPACE 0
  TCoord * coorT0 = malloc(sizeof(TCoord));
  coorT0->x = posx;
  coorT0->y = posy;
  // SPACE 1
  TCoord * coorT1 = malloc(sizeof(TCoord));
  coorT1->x = posx + SPACESIZE/2;
  coorT1->y = posy + goldNum*SPACESIZE + 1;
  // SPACE 2
  TCoord * coorT2 = malloc(sizeof(TCoord));
  coorT2->x = posx + SPACESIZE;
  coorT2->y = posy;
  // SPACE 3
  TCoord * coorT3 = malloc(sizeof(TCoord));
  coorT3->x = posx + SPACESIZE/2;
  coorT3->y = posy - goldNum*SPACESIZE;
  // SPACE 4
  TCoord * coorT4 = malloc(sizeof(TCoord));
  coorT4->x = posx - SPACESIZE/2;
  coorT4->y = posy - goldNum*SPACESIZE;
  // SPACE 5
  TCoord * coorT5 = malloc(sizeof(TCoord));
  coorT5->x = posx - SPACESIZE;
  coorT5->y = posy;
  // SPACE 6
  TCoord * coorT6 = malloc(sizeof(TCoord));
  coorT6->x = posx - SPACESIZE/2;
  coorT6->y = posy + goldNum*SPACESIZE + 1;

  // put Coordinates on the tiles
  M->coords[currTile][0] = coorT0;
  M->coords[currTile][1] = coorT1;
  M->coords[currTile][2] = coorT2;
  M->coords[currTile][3] = coorT3;
  M->coords[currTile][4] = coorT4;
  M->coords[currTile][5] = coorT5;
  M->coords[currTile][6] = coorT6;

  // Put the tile in the current tposition
  M->tileCount += 1;
}

void TMap_addNewTile(TMap * M, int pos, SDL_Renderer * R, TLista * E) {
  int posx = ((TCoord *) M->tiles[M->currTile])->x;
  int posy = ((TCoord *) M->tiles[M->currTile])->y;
  int des = 1.2438;
  int new_posx, new_posy;
  // depending by where the heroe is going
  switch (pos) {
    case NOR_EAST:
      new_posx = posx + 2*SPACESIZE;
      new_posy = posy + 2*des*SPACESIZE;
      break;
    case EAST:
      new_posx = posx + 2*SPACESIZE;
      new_posy = posy - 2*des*SPACESIZE;
      break;
    case SOUTH:
      new_posx = posx + SPACESIZE/2;
      new_posy = posy - 3*des*SPACESIZE;
      break;
    case SOU_WEST:
      new_posx = posx - 2*SPACESIZE;
      new_posy = posy - 2*des*SPACESIZE;
      break;
    case WEST:
      new_posx = posx - 2*SPACESIZE;
      new_posy = posy + 2*des*SPACESIZE;
      break;
    case NORTH:
      new_posx = posx - SPACESIZE/2;
      new_posy = posy + 3*des*SPACESIZE;
      break;
  }
  TMap_putNewTileCoords(M, new_posx, new_posy, R, TLista_pop(E)->elem);
}

void TMap_Render(TMap * M, SDL_Renderer * R) {
  // Render background
  SDL_Rect dst;
  dst.x = 0;
  dst.y = 0;
  dst.w = 600;
  dst.h = 600;
  SDL_RenderCopy(R, M->background, NULL, &dst);

  int i;
  // Render each surface of each tile
  // Uses the coordinates to do this
  for (i=0; i<NUMBER_OF_TILES; i++) {
    if (M->tiles[i] == NULL) {
      break;
    }
    TTiles_Render(M->tiles[i], R, M->coords[i]);
  }
}

void TMap_handleEvent(TMap * M, SDL_Event * e) {
  int i, r;
  // Call each the handler of each tile
  // uses the coordinates to do this
  for (i=0; i<NUMBER_OF_TILES; i++) {
    if (M->tiles[i] == NULL) {
      break;
    }
    r = TTiles_handleEvent(M->tiles[i], e, M->coords[i], &M->currSpace);
    if (r == 1) {
      M->currTile = i;
    }
  }
}
