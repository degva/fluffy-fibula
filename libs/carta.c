#include "carta.h"
#include <stdio.h>
#include <stdlib.h>

static fluFlyCart fluFly_CARTS [] ={
	{"move",2,1,"img1.png"},
	{"attack",2,2,"img1.png"},
	{"defend",2,3,"img1.png"},
	{"heal",2,4,"img1.png"},
	{"buy",2,5,"img1.png"},
	{NULL,0,0,NULL}
}


fluFlyCart * fluFlyCart_new(cont tchar *name,int points,int type, const tchar *img)
{	
	fluFlyCart * carta;
	carta = malloc( sizeof (lokenemy));
	carta-> name = name;
	carta-> points = points;
	carta-> type = type;
	carta->img=img;
	return carta;

};


TArray * fluFlyCart_create_carts()
{
	TArray * cartas;
	fluFlyCart* carta ; 
	int i;

	cartas = t_array_new();

		for ( i = 0 ; fluFly_CARTS[i].name != NULL, i++){
			carta = fluFlyCart_new ( fluFly_CARTS[i].name,
									 fluFly_CARTS[i].points,
									 fluFly_CARTS[i].type,
									 fluFly_CARTS[i].img);
			t_array_append( cartas ,carta);
	}
	return cartas;
};

fluFlyCart_modify_points(fluFlyCart * carta , int points)
{
	carta->point = carta->point + points;

}























