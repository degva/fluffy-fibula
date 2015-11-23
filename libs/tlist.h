#ifndef LISTAST_H
#define LISTAST_H

#include <tlibs.h>
typedef void * TElemento;

typedef struct nodo{
  TElemento elem;
  struct nodo *sig;
} TNodo;

typedef struct lista{
  TNodo *inicio;
  TNodo *fin;
  int numElem;
} TLista;


/* Crea una lista vacía */
void TLista_init(TLista *);
/* Libera la memoria ocupada por todos los elmentos de la lista */
void TLista_finalizar(TLista *);
/* Inserta un nuevo elemento en la lista */
void TLista_insertar(TLista *, TElemento);
/* Verifica si la lista está vacía */
int TLista_estaVacia(TLista *);
/* Elimina un elemento de la lista */
void TLista_eliminar(TLista *, TElemento);
/* Obtiene el número de elementos de la lista*/
int TLista_tamanho(TLista *);
/* Verifica si un elemento está en la lista */
int TLista_estaEnLista(TLista *, TElemento);
/* Imprime los elementos de la lista */
void TLista_imprimir(TLista *);
/* Cambia pointer de posicion */
void TLista_swapNodos(TLista *, int i, int j);
TNodo * TLista_takeNodo(TLista *L, int pos);
TNodo * TLista_pop(TLista  *L);
#endif  /* LISTAST_H */

