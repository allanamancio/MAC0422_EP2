#ifndef __AUX_H__
#define __AUX_H__

#include "structs.h"
#include <stdio.h>

extern pista *velodromo;
extern placar *meu_placar;
extern pthread_mutex_t mutex_pista;
extern int relogio;

int mod(int a, int b);

void imprime_pista();

void imprime_placar();

void aumenta_relogio();

#endif