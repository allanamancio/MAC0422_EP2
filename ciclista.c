//Conterá a struct ciclista e os métodos dos ciclistas

#include "ciclista.h"

int cria_ciclista(int posicao, int faixa, int id) {

	ciclista *c = malloc(sizeof(ciclista));
	c->v = 30;
	c->volta = 1;
	c->pos = posicao;
	c->faixa = faixa;
	c->pontos = 0;
	c->id = id;
	velodromo->circuito[faixa][posicao] = id;
	velodromo->total_ciclistas++;
	meu_placar->ranking[id - 1] = c;

	pthread_create(&(c->thread_id), NULL, ciclista_generico, &c);
}

int pode_pedalar(cicilista *c) {
	if (velodromo->circuito[c->faixa][mod(c->pos + 1, velodromo->tamanho)])
		return 0;
	return 1;
}

void ciclista_generico(ciclista *c) {
	int meu_tempo = 0;
	if (c->volta == 1) {
		pode_pedalar(c) pedala = 1;

		
	}
	else {

	}
}