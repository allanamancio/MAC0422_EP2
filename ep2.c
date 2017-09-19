//Conterá o simulador
#include <stdio.h>
#include "pista.h"
#include "ciclista.h"
#include "aux.h"

pista *velodromo;

int main(int argc, char *argv[]) {
	// argv[1] = d (tamanho da pista)
	// argv[2] = n (número de ciclistas)
	// argv[3] = v (número de voltas)
	// argv[4] = d (debug)

	int tamanho_pista;
	int numero_ciclistas;
	int numero_voltas;
	int debug;

	tamanho_pista = argv[1];
	numero_ciclistas argv[2];
	numero_voltas = argv[3];
	if (argc == 5) debug = argv[4];

	cria_pista(velodromo, tamanho_pista);

	/*Cria os ciclistas nas suas posições e faixas corretas (10 faixas e tamanho_pista posições) a partir da posição e 
	 *faixa 0.*/
 	for (int i = 0; i < numero_ciclistas; i = mod(i - 1, tamanho_pista))
		for (int j = 0; j < 10 && numero_ciclistas > 0; j++) { 
			cria_ciclista(i, j);
			numero_ciclistas--;
		}
}
