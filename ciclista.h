#ifndef __CICLISTA_H__
#define __CICLISTA_H__

#include <stdlib.h>
#include "structs.h"

extern pista *velodromo;
extern placar *meu_placar;

//inicializa a struct e cria a thread
int cria_ciclista(int posicao, int faixa, int id);
 

int destroi_ciclista(ciclista *c);

//Retorna 1 se o ciclista puder pedalar e 0 c.c.
int pode_pedalar(ciclista *c);

//Retorna 1 se o ciclista puder ultrapassar e 0 c.c.
int pode_ultrapassar(ciclista *c);

//Recebe um ponteiro para um ciclista. Retorna 1 se o ciclista quebrou e 0 c.c.
int sorteia_quebra(ciclista *c);

//Recebe um ponteiro para um ciclista, sorteia sua velocidade e preenche a struct
int sorteia_velocidade(ciclista *c);

void ciclista_generico();

#endif