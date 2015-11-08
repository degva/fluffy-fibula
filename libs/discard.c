#include "discard.h"

fluFlyCartDiscard * fluFlyCartDiscard_new()
{
	fluFlyCartDiscard * discard
	discard = malloc (sizeof (fluFlyCartDiscard));
	discard ->list = t_mlist_new();
	//discard -> game = game ;
	return discard
}

fluflyCartDiscard * fluflyCartDiscard_add_element (fluflyCartDiscard * discard, fluflyCart * carta)
{
	t_mlist_prepend (T_MLIST (discard -> list), element);
}

fluFlyCartDiscard * fluFlyCartDiscard_shuffle (fluFlyCartDiscard * discard )
{
	fluflyCartDiscard discard[1000];
    TList *next = NULL; 
    TList *start = NULL; 
    TList *end = NULL;
    int i = 0;
    
    memset(discard, 0, sizeof(discard));
    srand ( time(NULL) );
    start = &discard[ rand() % (1000)];           
    end = start;
    
    for (i = 0; i < 999; ++i)
    {   
        end->next = end;
        while ((pNext = &discard[ rand() % (1000)]) && pNext->next);
        end->next = pNext;
        end = pNext;
    }
    
}



}