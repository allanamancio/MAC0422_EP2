#ifndef __PLACAR_H__
#define __PLACAR_H__

#include "structs.h"
#include <stdlib.h>

extern placar *meu_placar;

int cria_placar(int d);

void atribui_pontos(ciclista *c);

void ordena_placar();

#endif