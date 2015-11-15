/* 
 * File:   main.c
 * Author: alulab
 *
 * Created on 9 de noviembre de 2015, 11:21 AM
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "discard.h"
#include "action.h"
#include "tmlist.h"

int main(int argc, char** argv) {
    TArray * cartas= fluFlyCart_create_carts();
    int i,n=5;
    srand(time(NULL));
    TArray * cartas_p;
    cartas_p = fluFlyCartDiscard_shuffle ( cartas,  n );
    for ( i = 0;i<5;i++){
        fluFlyCart* carta = cartas_p->vector[i];
        printf("%s\t   %d\t   %d\t   %s \n",carta->name,
	    carta->type,
	    carta->points,
            carta->img);
       
    }
    
    printf("\n");
    fluFlyCartAction * action;
    action = fluFlyCartarray_to_action(cartas,5);
    TList * col = action->list->start;
    
    for ( i=0 ; i<5 && col!= NULL; i++){
        fluFlyCart* cosa = col->data;
        fluFlyCart* carta = cosa;
        printf("%s\t   %d\t   %d\t   %s \n",carta->name,
	    carta->type,
	    carta->points,
            carta->img);
        col=col->next;
        
    } 
    

    return (EXIT_SUCCESS);
}
*/

