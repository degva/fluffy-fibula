#include "pelea.h"

// incluir donde estan todas las librerias 
bool TFight_heroVsEnemy(THeroe * pj, TEnemy * enemy, int ataque){
  bool ret = false; // Hero loses

  int aH = ataque;
  int aE = enemy->ataque;

  int dH = pj->def;
  int dE = enemy->defensa;

  if ((aH > dE) && (dH >=aE))	{
    ret = true;
  } 
  /*
  else {
    if ((aH > dE) && (dH < aE)) {
      return 2;// se entrega carta bounds
    } else {
      if ((aH < dE) && (dH >= aE)) {
        ret = false;
      } else {
        ret = false; // se entrega carta bounds
      }
    }
  }
  */
  return ret;
}
