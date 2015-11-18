#include "mano.h"
#include "tmlist.h"

TCartMano * TCartMano_new()
{
	TCartMano * mano;
	mano = malloc(sizeof(TCartMano));
	mano->list = t_mlist_new();
	return mano;
}

void TCartMano_addElement (TCartMano * mano, TCart * carta)
{
    t_mlist_prepend (T_MLIST (mano -> list), carta);
}

void TCardMano_selectCard(TCardMano *, int i) {

}
