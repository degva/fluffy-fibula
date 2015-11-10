#ifndef __T_ARRAY_H__
#define __T_ARRAY_H__

#include "ttypes.h"
typedef struct _TArray TArray;
struct _TArray
{
  tpointer *vector;
  int len;
  TFunc free_func;
};

TArray * t_array_new ();
//+void t_array_foreach (TArray * array, TFunc func, tpointer user_data);
void t_array_append (TArray * array, tpointer data);


#endif	/* TTARRAY_H */

