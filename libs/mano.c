#include "mano.h"
#include "tmlist.h"

TCartMano * TCartMano_new()
{
	TCartMano * mano;
	mano = malloc (sizeof (TCartMano));
	mano ->list = t_mlist_new();
	//mano -> game = game ;
	return mano;
}

TCartMano * TCartMano_add_element (TCartMano * mano, TCart * carta)
{
    t_mlist_prepend (T_MLIST (mano -> list), carta);
}

