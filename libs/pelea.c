// incluir donde estan todas las librerias 
int pelea(TPJ * pj,TEnemy * enemy){
	int aH = pj-> atk;
	int aE = enemy-> ataque;
	int dH = pj->def;
	int dE = enemy -> defensa;

	if ((aH > dE) && (dH >=aE))	{
		return 1;
	} else {
			if ((aH > dE) && (dH < aE)) {
				return 2;// se entrega carta bounds
			} else {
					if ((aH < dE) && (dH >= aE)) {
						 return 3;
					} else {
							return 4 // se entrega carta bounds
						}
				}
		}
}
