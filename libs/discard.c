#include "discard.h"
#include "tmlist.h"
TCartDiscard * TCartDiscard_new()
{
	TCartDiscard * discard;
	discard = malloc (sizeof (TCartDiscard));
	discard ->list = t_mlist_new();
	//discard -> game = game ;
	return discard;
}

TCartDiscard * TCartDiscard_add_element (TCartDiscard * discard, TCart * carta)
{
    t_mlist_prepend (T_MLIST (discard -> list), carta);
}


TArray * TCartDiscard_to_array(TCartDiscard * discard){
    TArray *array ;
            array = t_array_new();
    TList * list = discard->list->start;
    while (list!= NULL){
        t_array_append ( array,  list->data);
        list=list->next;
    }
    return (array) ;


}
TArray * TCartDiscard_shuffle (TArray * array, int n ){
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


