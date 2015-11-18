/* 
 * File:   pj.h
 * Author: fredy
 *
 * Created on 16 de noviembre de 2015, 12:18 AM
 */

#ifndef PJ_H
#define	PJ_H
#include "ttarray.h"


typedef struct _fluFlyPJ fluFlyPJ;
struct _fluFlyPJ {
	const tchar *name ;
	int def;
        int exp;
        int nivel;
	const tchar *img;
        fluFlyCartMano *mano;
        
	
};


fluFlyPJ * fluFlyPJ_new(const tchar *name,int def,int exp, int nivel,const tchar *img,fluFlyCartMano * mano);




#endif	/* PJ_H */

