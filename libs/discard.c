#include "discard.h"
#include "tmlist.h"
fluFlyCartDiscard * fluFlyCartDiscard_new()
{
	fluFlyCartDiscard * discard;
	discard = malloc (sizeof (fluFlyCartDiscard));
	discard ->list = t_mlist_new();
	//discard -> game = game ;
	return discard;
}

fluFlyCartDiscard * fluFlyCartDiscard_add_element (fluFlyCartDiscard * discard, fluFlyCart * carta)
{
    t_mlist_prepend (T_MLIST (discard -> list), carta);
}


TArray * fluFlyCartDiscard_to_array(fluFlyCartDiscard * discard){
    TArray *array ;
            array = t_array_new();
    TList * list = discard->list->start;
    while (list!= NULL){
        t_array_append ( array,  list->data);
        list=list->next;
    }
    return (array) ;


}
TArray * fluFlyCartDiscard_shuffle (TArray * array, int n ){
    //colocar la semilla en el inicio
    //srand(time(NULL));
    int r = rand(); 
    int i;
    
    for ( i = n-1 ; i >= 1; i--){
        int pos = rand() % i;
        tpointer *aux;
        aux = array->vector[i];
        array->vector[i] = array->vector[pos];
        array->vector[pos] = aux;
    }
    return array;
    /* creditos juan tomairo  */
}


