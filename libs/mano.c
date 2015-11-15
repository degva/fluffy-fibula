#include "mano.h"
#include "tmlist.h"

fluFlyCartMano * fluFlyCartMano_new()
{
	fluFlyCartMano * mano;
	mano = malloc (sizeof (fluFlyCartMano));
	mano ->list = t_mlist_new();
	//mano -> game = game ;
	return mano;
}

fluFlyCartMano * fluFlyCartMano_add_element (fluFlyCartMano * mano, fluFlyCart * carta)
{
    t_mlist_prepend (T_MLIST (mano -> list), carta);
}

