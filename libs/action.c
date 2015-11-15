#include "action.h"
#include "tmlist.h"


fluFlyCartAction * fluFlyCartAction_new()
{
	fluFlyCartAction * Action;
	Action = malloc (sizeof (fluFlyCartAction));
	Action ->list = t_mlist_new();
	//Action -> game = game ;
	return Action;
}

fluFlyCartAction * fluFlyCartAction_add_element (fluFlyCartAction * Action, fluFlyCart * carta)
{
    t_mlist_prepend (T_MLIST (Action -> list), carta);
}


fluFlyCartAction * fluFlyCartarray_to_action(TArray * array,int n){
    fluFlyCartAction * action = fluFlyCartAction_new();
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
