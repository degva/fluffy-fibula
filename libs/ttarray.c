#include "ttarray.h"

#define _t_alloc_array()     malloc(sizeof (TArray))
#define _t_realloc_vector(a, sz)   t_alloc(a,tpointer,sz)

TArray *
t_array_new ()
{
  TArray *array;

  array = _t_alloc_array ();
  array->len = 0;
  array->vector = NULL;

  return array;
}


void
t_array_append (TArray * array, tpointer data)
{
  array->len++;
  array->vector = realloc (array->vector, sizeof (tpointer) * array->len);
  array->vector[array->len - 1] = data;  
}

