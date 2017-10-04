//Conterá o simulador
#include <stdio.h>
#include <pthread.h>
#include "pista.h"
#include "placar.h"
#include "ciclista.h"
#include "aux.h"

pista *velodromo;
placar *meu_placar;
int intervalo_atualizacao;
int debug;
pthread_barrier_t barreira;

int main(int argc,  char *argv[]) {
	// argv[1] = d (tamanho da pista)
	// argv[2] = n (número de ciclistas)
	// argv[3] = v (número de voltas)
	// argv[4] = d (debug)

	int tamanho_pista;
	int numero_ciclistas;
	int numero_voltas;
	int i, j; //contadores

	//Inicializa argumentos
	tamanho_pista = atoi(argv[1]);
	numero_ciclistas = atoi(argv[2]);
	numero_voltas = atoi(argv[3]);
	debug = 0;
	if (argc == 5) debug = 1;
	meu_placar = malloc(sizeof(placar));
	velodromo = malloc(sizeof(pista));

	//Inicializa barreira
	if (pthread_barrier_init(&barreira, NULL, numero_ciclistas)) {
		printf("ERROR(main): Barreira não foi inicializada");
		exit(1);
	}

	cria_pista(tamanho_pista);
	cria_placar(numero_ciclistas);


	/*Cria os ciclistas nas suas posições e faixas corretas (10 faixas e tamanho_pista posições) a partir da posição e 
	 *faixa 0.*/
 	for (i = 0; numero_ciclistas > 0; i = mod(i - 1, tamanho_pista))
		for (j = 0; j < 10 && numero_ciclistas > 0; j++) { 
			cria_ciclista(i, j, numero_ciclistas);
			numero_ciclistas--;
		}

	//Calcula

	//Executa
	//Barreira 0
	//Atualiza
	//Verifica

	imprime_pista();
	imprime_placar();

	return 1;
}
