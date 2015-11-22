/* 
 * File:   pj.h
 * Author: fredy
 *
 * Created on 16 de noviembre de 2015, 12:18 AM
 */

#ifndef PJ_H
#define	PJ_H
#include "ttarray.h"


typedef struct _TPJ TPJ;
struct _TPJ {
	const tchar *name ;
	int def;
  int exp;
  int nivel;
	const tchar *img;
  TCartMano *mano;
};


TPJ * TPJ_new(const tchar *name,int def,int exp, int nivel,const tchar *img,TCartMano * mano);




#endif	/* PJ_H */

