#ifndef __PLACAR_H__
#define __PLACAR_H__

typedef struct {
	ciclista *ranking;
	int *pontos;
} placar;

void atribui_pontos(*ciclista, *placar);

void ordena_placar(*placar);

#endif