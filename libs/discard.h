#ifndef _DISCARD_H
#define _DISCARD_H

#include <string.h>
#include <time.h>

#include "carta.h"
typedef struct _TCartDiscard TCartDiscard ;

struct _TCartDiscard{
	//TGame *game;
	TMList *list;

};

TCartDiscard * TCartDiscard_new();
TCartDiscard * fluflyCartDiscard_add_element(TCartDiscard *discard , TCart * carta);


#endif
