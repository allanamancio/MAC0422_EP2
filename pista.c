//Conterá os métodos da pista
#include "pista.h"

int cria_pista(int d, int voltas, int ciclistas) {
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
	velodromo->numero_voltas = voltas;
	velodromo->tamanho = d;
	velodromo->v_max = 30;
	velodromo->total_ciclistas = ciclistas;
	velodromo->finalizados = 0;
	return 1;
}

void pedala(ciclista *c) {
	velodromo->circuito[c->faixa][c->pos] = 0;
	velodromo->circuito[c->faixa][mod(c->pos + 1, velodromo->tamanho)] = c->id;
	c->pos = mod(c->pos + 1, velodromo->tamanho);
}

void ultrapassa(ciclista *c) {
	velodromo->circuito[c->faixa][c->pos] = 0;
	velodromo->circuito[c->faixa + 1][mod(c->pos + 1, velodromo->tamanho)] = c->id;
	c->pos = mod(c->pos + 1, velodromo->tamanho);
	c->faixa++;
}

void volta_faixa(ciclista *c) {
	velodromo->circuito[c->faixa][c->pos] = 0;
	velodromo->circuito[c->faixa - 1][mod(c->pos + 1, velodromo->tamanho)] = c->id;
	c->pos = mod(c->pos + 1, velodromo->tamanho);
	c->faixa--;
}

ciclista *busca_ciclista(int id) {
	int i;
	for (i = 0; i < velodromo->total_ciclistas; i++)
		if (meu_placar->ranking[i]->id == id) return meu_placar->ranking[i];
	return NULL;
}