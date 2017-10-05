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
	switch (c->v) {
		case 30:
			if (relogio%120 == 0)
				return 1;
			break;
		case 60:
			if (relogio%60 == 0)
				return 1;
			break;
		case 90:
			if (relogio%40 == 0)
				return 1;
			break;
	}

	return 0;
}

int pode_ultrapassar(cicilista *c) {
	ciclista *c_frente;
	if (velodromo->circuito[c->faixa][mod(c->pos + 2, velodromo->tamanho)]) return 0;
	if (c->faixa == 0) return 0;
	else if (velodromo->circuito[c->faixa - 1][mod(c->pos + 1, velodromo->tamanho)]) return 0;
	c_frente = busca_ciclista(velodromo->circuito[c->faixa][mod(c->pos + 1, velodromo->tamanho)]);
	if (c->v <= c_frente->v) return 0;

	switch (c->v) {
		case 30:
			if (relogio%120 == 0)
				return 1;
			break;
		case 60:
			if (relogio%60 == 0)
				return 1;
			break;
		case 90:
			if (relogio%40 == 0)
				return 1;
			break;
	}

	return 0;
}

void ciclista_generico(ciclista *c) {
	if (c->volta == 1) {
		pthread_mutex_lock(&mutex_ptable);
		if (velodromo->circuito[c->faixa][mod(c->pos + 1, velodromo->tamanho)]) {
			if (pode_ultrapassar(c)) {

			}
		}
		else if (pode_pedalar(c)) {
			pedala(c);
		}
		pthread_mutex_unlock(&mutex_ptable);
	}
	else {

	}
}

	if (c->v == 30)
	if ()
		return 0;
	return 1;