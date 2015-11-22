#include <tlibs.h>
#include "ttarray.h"

#ifndef CARTAST_H
#define CARTAST_H
typedef struct _TCart TCart;
struct _TCart {
	const tchar *name ;
	int points;
	int type;
	const tchar *img;
  bool selected;
};


TCart * TCart_new(const tchar *name,int points,int type, const tchar *img);

TArray * TCart_create_carts();

void TCart_modify_points (TCart * , int points);
void TCart_render (TCart *);

#endif	/* CARTA_H */

