#include "carta.h"

#include <stdio.h>
#include <stdlib.h>

static TCart FLUFLY_CARTS[] = { 
	{"move",2,1,"img1.png"},
	{"attack",2,2,"img1.png"},
	{"defend",2,3,"img1.png"},
	{"heal",2,4,"img1.png"},
	{"buy",2,5,"img1.png"},
	{NULL,0,0,NULL}
};


TCart * TCart_new(const tchar *name,int points,int type, const tchar *img)
{	
	TCart * carta;
	carta = malloc( sizeof (TCart));
	carta-> name = name;
	carta-> points = points;
	carta-> type = type;
	carta->img=img;
	return carta;

};


TArray * TCart_create_carts()
{
	TArray * cartas;
	TCart* carta ; 
	int i,j;
        
	cartas = t_array_new();
        for(j=0;j<16;j++){
            for ( i = 0 ; FLUFLY_CARTS[i].name != NULL; i++){
                carta = TCart_new ( FLUFLY_CARTS[i].name,
                FLUFLY_CARTS[i].points+j,
                FLUFLY_CARTS[i].type,
                FLUFLY_CARTS[i].img);
                            t_array_append( cartas ,carta);
            }
            
        }
        return (cartas);
};

void TCart_modify_points(TCart * carta , int points)
{
	carta->points = carta->points + points;

}


