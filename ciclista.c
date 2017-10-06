//Conterá a struct ciclista e os métodos dos ciclistas

#include "ciclista.h"

#include <stdio.h> // DEBUG

int cria_ciclista(int posicao, int faixa, int id) {

	ciclista *c = malloc(sizeof(ciclista));
	if (c == NULL) return 0;
	c->v = 30;
	c->volta = 0; //Pois o ciclista não iniciou uma volta (ainda)
	c->pos = posicao;
	c->faixa = faixa;
	c->faixa_origem = faixa;
	c->pontos = 0;
	c->id = id;
	velodromo->circuito[faixa][posicao] = id;
	velodromo->total_ciclistas++;
	meu_placar->ranking[id - 1] = c;
	pthread_create(&(c->thread_id), NULL, ciclista_generico, c);
	return 1;
}

int pode_pedalar(ciclista *c) {
	switch (c->v) {
		case 30:
			if (relogio%120 == 0)
				return 1;
		case 60:
			if (relogio%60 == 0)
				return 1;
		case 90:
			if (relogio%40 == 0)
				return 1;
	}

	return 0;
}

int pode_ultrapassar(ciclista *c) {
	ciclista *c_frente;
	if (c->faixa == 9 || velodromo->circuito[c->faixa + 1][mod(c->pos + 1, velodromo->tamanho)]) return 0;
	c_frente = busca_ciclista(velodromo->circuito[c->faixa][mod(c->pos + 1, velodromo->tamanho)]);
	if (c->v <= c_frente->v) return 0;

	return 1;
}


void reduz_velocidade(ciclista *c) {
	ciclista *c_frente;
	c_frente = busca_ciclista(velodromo->circuito[c->faixa][mod(c->pos + 1, velodromo->tamanho)]);
	c->v = c_frente->v;
}

int consegue_voltar(ciclista *c) {
	printf("(i,j): %d %d\n",c->faixa -1, mod(c->pos + 1, velodromo->tamanho));
	if (velodromo->circuito[c->faixa -1][mod(c->pos + 1, velodromo->tamanho)] || !pode_pedalar(c)) return 0;
	return 1;
}

#define cast_c ((ciclista *) c)

void *ciclista_generico(void *c) {
	int pedalei = 0;
	while (cast_c->volta <= velodromo->numero_voltas) {
		if (cast_c->volta <= 1) {
			pthread_mutex_lock(&mutex_pista);
			if (cast_c->faixa_origem != cast_c->faixa && consegue_voltar(cast_c)) {
				volta_faixa(cast_c); //Se aproxima da faixa original
				pedalei = 1;
			}
			else {
				if (velodromo->circuito[cast_c->faixa][mod(cast_c->pos + 1, velodromo->tamanho)]) {
					if (pode_ultrapassar(cast_c)) {
						ultrapassa(cast_c);
						pedalei = 1;

					}
					else reduz_velocidade(cast_c);
				}
				else if (pode_pedalar(cast_c)) {
					pedala(cast_c);
					pedalei = 1;
				}
			}
			pthread_mutex_unlock(&mutex_pista);
		}

		/*Demais voltas*/
		else {
			pthread_mutex_lock(&mutex_pista);
			pthread_mutex_unlock(&mutex_pista);
		}
		pthread_mutex_unlock(&mutex_pista);

		if (pedalei) {
			if (!cast_c->pos) {
				cast_c->volta++;
				pthread_mutex_lock(&mutex_pista);
				imprime_pista();
				pthread_mutex_unlock(&mutex_pista);
			}
			pedalei = 0;
		}

		if (pthread_barrier_wait(&barreira) == PTHREAD_BARRIER_SERIAL_THREAD) {
			aumenta_relogio();
		}
	}
	
	return NULL;
}