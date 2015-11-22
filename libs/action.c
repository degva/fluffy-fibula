#include "action.h"
#include "tmlist.h"


TCartAction * TCartAction_new()
{
	TCartAction * Action;
	Action = malloc (sizeof (TCartAction));
	Action ->list = t_mlist_new();
	//Action -> game = game ;
	return Action;
}

TCartAction * TCartAction_add_element (TCartAction * Action, TCart * carta)
{
    t_mlist_prepend (T_MLIST (Action -> list), carta);
}


TCartAction * TCartarray_to_action(TArray * array,int n){
    TCartAction * action = TCartAction_new();
    TList * inicio =action->list->start;
    inicio=NULL;
    int i = 0;
    tpointer * array_n=array->vector[i];
    while (n!=0){
        inicio=t_list_prepend ( inicio, array_n);
        i++;
        array_n= array->vector[i];
        n--;
    }
    action->list->start= inicio;
    return (action) ;


}
