//Conterá a struct pista e os métodos da pista
#include "pista.h"

int cria_pista(int d) {
	int i, j;
    int **circuito = (int**)malloc(10*sizeof(int*));
	if (circuito == NULL) return 0;
	for (i = 0; i < 10; i++) {
		circuito[i] = (int*)malloc(d*sizeof(int));
		if (circuito[i] == NULL) return 0;
		for (j = 0; j < d; j++)
			circuito[i][j] = 0;
	}
	velodromo->circuito = circuito;
	velodromo->total_ciclistas = 0;
	velodromo->tamanho = d;
	return 1;
}