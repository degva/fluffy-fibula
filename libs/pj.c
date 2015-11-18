#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pj.h"

/*static fluFlyPJ FLUFLY_PJ[] = { 
	{"NULL",4,0,1,"img1_PJ.png"},
	{NULL,0,0,NULL}
};
*/
fluFlyPJ * fluFlyPJ_new(const tchar *name,int def,int exp, int nivel,const tchar *img,fluFlyCartMano * mano){
	
	fluFlyPJ * pj;
	pj = malloc( sizeof (fluFlyPJ));
	pj->def= def;
	pj->exp = exp;
	pj->img = img;
	pj->mano=mano;
        pj->name=name;
        pj->nivel=nivel;
	return pj;

};
//const tchar *name,int def,int exp, int nivel,const tchar *img
// COMPLETAR TODO , STAR WARDS IV GOGOG
