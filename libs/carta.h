#ifndef CARTAST_H
#define CARTAST_h

struct fluFlyCart {
	const tchar *name ;
	int points;
	int type;
	const tchar *img;
	
};


fluFlyCart * fluFlyCart_new(cont tchar *name,int points,int type, const tchar *img);

TArray * fluFlyCart_create_carts();
fluFlyCart_free ( fluFlyCart * );

fluFlyCart_modify_points(fluFlyCart * carta , int points);
