/* 
 * File:   Mano.h
 * Author: fredy
 *
 * Created on 14 de noviembre de 2015, 11:26 PM
 */

#ifndef MANO_H
#define	MANO_H
typedef struct _TCartMano TCartMano;
struct _TCartMano{
	//TGame *game;
	TMList *list;

};
TCartMano * TCartMano_new();
TCartMano * fluflyCartMano_add_element(TCartMano *discard , TCart * carta);




#endif	/* MANO_H */

