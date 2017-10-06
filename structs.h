#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <pthread.h>
//Conterá a struct ciclista e os métodos dos ciclistas
typedef struct {
	int v; //velocidade
	int volta;
	int pos; //índice da pista no qual o ciclista está	
	int faixa; //em qual faixa o ciclista está
	int faixa_origem;
	int pontos;
	int id; //Deve ser diferente de 0
	pthread_t thread_id;
} ciclista;

//Conterá a struct pista e os métodos da pista
typedef struct {
	int **circuito;
	int total_ciclistas;
	int finalizados; //Ciclistas que terminaram a corrida
	int numero_voltas;
	int tamanho;
	int v_max; //velocidade máxima corrente na pista
} pista;

typedef struct {
	ciclista **ranking;
	int *pontos;
} placar;

#endif