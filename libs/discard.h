#ifndef _DISCARD_H
#define _DISCARD_H

#include <string.h>
#include <time.h>

#include "carta.h"
typedef struct _fluFlyCartDiscard fluFlyCartDiscard ;

struct _fluFlyCartDiscard{
	//fluFlyGame *game;
	TMList *list;

};

fluFlyCartDiscard * fluFlyCartDiscard_new();
fluFlyCartDiscard * fluflyCartDiscard_add_element(fluFlyCartDiscard *discard , fluFlyCart * carta);


#endif
