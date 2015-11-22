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
	TMList *list;
};

TCartMano * TCartMano_new();
void TCardMano_addElement(TCartMano *, TCart *);
void TCardMano_selectCard(TCardMano *, int i);
void TCardMano_crearMano(TCardMano *);



#endif	/* MANO_H */

