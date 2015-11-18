#include <tlibs.h>
#include "ttarray.h"

#ifndef CARTAST_H
#define CARTAST_H
typedef struct _fluFlyCart fluFlyCart;
struct _fluFlyCart {
	const tchar *name ;
	int points;
	int type;
	const tchar *img;
  bool selected;
};


fluFlyCart * fluFlyCart_new(const tchar *name,int points,int type, const tchar *img);

TArray * fluFlyCart_create_carts();

void fluFlyCart_modify_points (fluFlyCart * , int points);
void fluFlyCart_render (fluFlyCart *);

#endif	/* CARTA_H */

