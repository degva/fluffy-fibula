#ifndef ACTION_H
#define ACTION_H


#include <string.h>
#include "carta.h"

#include "ttarray.h"


typedef struct _TCartAction TCartAction ;

struct _TCartAction{
	//TGame *game;
	TMList *list;

};

TCartAction * TCartAction_new();



#endif	/* ACTION_H */

