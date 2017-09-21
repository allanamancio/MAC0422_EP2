#ifndef __CICLISTA_H__
#define __CICLISTA_H__
//Conterá a struct ciclista e os métodos dos ciclistas

typedef struct {
	int v; //velocidade
	int volta;
	int pos; //índice da pista no qual o ciclista está	
	int faixa; //em qual faixa o ciclista está
	int pontos;
} ciclistas;

//inicializa a struct e cria a thread
int cria_ciclista(int posicao, int faixa);
 

int destroi_ciclista(ciclista *c);

//Retorna 1 se o ciclista puder ultrapassar e 0 c.c.
int pode_pedalar(ciclista *c);

//Retorna 1 se o ciclista puder ultrapassar e 0 c.c.
int pode_ultrapassar(ciclista *c);

//Recebe um ponteiro para um ciclista. Retorna 1 se o ciclista quebrou e 0 c.c.
int sorteia_quebra(ciclista *c);

//Recebe um ponteiro para um ciclista, sorteia sua velocidade e preenche a struct
int sorteia_velocidade(ciclista *c);