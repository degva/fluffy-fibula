#ifndef ACTION_H
#define ACTION_H


#include <string.h>
#include "carta.h"

#include "ttarray.h"


typedef struct _fluFlyCartAction fluFlyCartAction ;

struct _fluFlyCartAction{
	//fluFlyGame *game;
	TMList *list;

};

fluFlyCartAction * fluFlyCartAction_new();



#endif	/* ACTION_H */

