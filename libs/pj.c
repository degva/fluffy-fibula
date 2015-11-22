#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pj.h"

/*static TPJ FLUFLY_PJ[] = { 
	{"NULL",4,0,1,"img1_PJ.png"},
	{NULL,0,0,NULL}
};
*/
TPJ * TPJ_new(const tchar *name,int def,int exp, int nivel,const tchar *img,TCartMano * mano){
	
	TPJ * pj;
	pj = malloc( sizeof (TPJ));
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
