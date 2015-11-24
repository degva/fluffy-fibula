#include "tlist.h"

/* Crea una lista vacía */
void TLista_init(TLista *L) {
  L->inicio = NULL; //(*L).inicio = NULL;
  L->fin = NULL; //  (*L).fin = NULL;
  L->numElem = 0;
}

/* Verifica si la lista está vacía */
int TLista_estaVacia(TLista *L) {
  return L->numElem == 0;
}

/* Libera la memoria ocupada por todos los elmentos de la lista */
void TLista_finalizar(TLista *L) {
  TNodo *ptrRec;
  ptrRec = L->inicio;
  while (ptrRec) {
    L->inicio = L->inicio->sig;
    free(ptrRec);
    ptrRec = L->inicio;
  }
  L->fin = NULL;
  L->numElem = 0;
}

/* Inserta un nuevo elemento en la lista */
void TLista_insertar(TLista *L, TElemento nuevoElem) {
  TNodo *ptrNuevo;
  ptrNuevo = malloc(sizeof (TNodo));

  if (ptrNuevo != NULL) {
    // Crear el nuevo nodo
    ptrNuevo->elem = nuevoElem;
    ptrNuevo->sig = NULL;
    // Insertar el nuevo nodo al final de la lista
    if (!TLista_estaVacia(L)) {
      L->fin->sig = ptrNuevo;
    } else {
      L->inicio = ptrNuevo;
    }
    L->fin = ptrNuevo;
    (L->numElem)++;
  }
}

/* Elimina un elemento de la lista */
void TLista_eliminar(TLista *L, TElemento e) {
  TNodo *ptrRec, *ptrAnt;

  // if (TLista_estaVacia(L)) return;

  ptrRec = L->inicio;
  ptrAnt = NULL;
  // Buscar el elemento en la lista
  while (ptrRec != NULL && ptrRec->elem != e) {
    ptrAnt = ptrRec;
    ptrRec = ptrRec->sig;
  }

  if (ptrRec != NULL) {// Encontró el elemento a eliminar
    if (ptrAnt == NULL) {// Es el primer elemento de la lista
      L->inicio = L->inicio->sig;
    }
    if (ptrRec == L->fin) { // Es el último elemento de la lista
      L->fin = ptrAnt;
      if (L->fin != NULL) L->fin->sig = NULL;
    } else if (ptrAnt != NULL) {
      ptrAnt->sig = ptrRec->sig;
    }
    free(ptrRec);
    (L->numElem)--;
  }
}

/* Obtiene el número de elementos de la lista*/
int TLista_tamanho(TLista *L) {
  return L->numElem;
}

/* Verifica si un elemento está en la lista */
int TLista_estaEnLista(TLista *L, TElemento e) {
  TNodo *ptrRec = L->inicio;
  while (ptrRec != NULL) {
    if (ptrRec->elem == e) return 1;
    ptrRec = ptrRec->sig;
  }
  return 0;
}

/* Imprime los elementos de la lista */
void TLista_imprimir(TLista *L) {
  TNodo *ptrRec = L->inicio;
  while (ptrRec != NULL) {
    // printf("%d ", ptrRec->elem);
    ptrRec = ptrRec->sig;
  }
}

TNodo * TLista_takeNodo(TLista *L, int pos) {
  TNodo *nodo, *nodoAnt;
  int i;
  nodoAnt = NULL;
  nodo = L->inicio;
  if (pos == 0) {
    L->inicio = nodo->sig;
  } else {
    for (i=0; i<pos; i++) {
      if (nodo->sig != NULL) {
        nodoAnt = nodo;
        nodo = nodo->sig;
      } else {
        break;
      }
    }
    if (nodo->sig == NULL) {
      nodoAnt->sig = NULL;
    } else {
      nodoAnt->sig = nodo->sig;
    }
  }
  L->numElem--;
  nodo->sig = NULL;
  return nodo;
}

void TLista_putNodoIn(TLista *L, TNodo *N, int pos) {
  TNodo *nodo, *nodoAnt;
  int i;
  nodoAnt = NULL;
  nodo = L->inicio;
  if (pos == 0) {
    N->sig = L->inicio;
    L->inicio = N;
  } else if (pos == TLista_tamanho(L) + 1) {
    L->fin->sig = N;
    L->fin = N;
  } else {
    for (i=0; i<pos; i++) {
      nodoAnt = nodo;
      nodo = nodo->sig;
    }
    nodoAnt->sig = N;
    N->sig = nodo;
  }
  L->numElem++;
}

/* Cambia poitner de posicion */
void TLista_swapNodos(TLista *L, int i, int j) {
  if (i < 0)
    i = 0;
  if (j < 0)
    j = 0;
  TNodo * nodo1 = TLista_takeNodo(L, i);
  TNodo * nodo2 = TLista_takeNodo(L, j);
  TLista_putNodoIn(L, nodo1, j);
  TLista_putNodoIn(L, nodo2, i);
}

TNodo * TLista_pop(TLista * L) {
  TNodo * nodo = L->inicio;
  L->inicio = L->inicio->sig;
  L->numElem--;
  return nodo;
}
