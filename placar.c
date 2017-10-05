#include "placar.h"

int cria_placar(int d) {
	int i;
    ciclista **ranking = (ciclista**)malloc(d*sizeof(ciclista*));
    int *pontos = (int*)malloc(d*sizeof(int));
	if (ranking == NULL || pontos == NULL) return 0;
	for (i = 0; i < d; i++) {
		pontos[i] = 0;
		ranking[i] = NULL;
	}
	meu_placar->ranking = ranking;
	meu_placar->pontos = pontos;
	return 1;
}
