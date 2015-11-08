#ifndef __T_ARRAY_H__
#define __T_ARRAY_H__

#include "ttypes.h"

struct TArray
{
  tpointer *vector;
  int len;
  TFunc free_func;
};

TArray * t_array_new ();
void t_array_append (TArray * array, tpointer data);