/* 
 * File:   Mano.h
 * Author: fredy
 *
 * Created on 14 de noviembre de 2015, 11:26 PM
 */

#ifndef MANO_H
#define	MANO_H
typedef struct _fluFlyCartMano fluFlyCartMano;
struct _fluFlyCartMano{
	//fluFlyGame *game;
	TMList *list;

};
fluFlyCartMano * fluFlyCartMano_new();
fluFlyCartMano * fluflyCartMano_add_element(fluFlyCartMano *discard , fluFlyCart * carta);




#endif	/* MANO_H */

