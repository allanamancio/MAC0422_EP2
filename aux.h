#ifndef __AUX_H__
#define __AUX_H__

#include "structs.h"
#include <stdio.h>

extern pista *velodromo;
extern placar *meu_placar;
extern pthread_mutex_t mutex_pista;
extern int relogio;
extern int debug;

int mod(int a, int b);

void imprime_pista();

void imprime_placar();

// Atualiza o tempo do relógio
void aumenta_relogio();

int conta_digitos(int a);

#endif