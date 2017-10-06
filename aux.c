#include "aux.h"

//fonts color
#define FBLACK      "\033[30;"
#define FRED        "\033[31;"
#define FGREEN      "\033[32;"
#define FYELLOW     "\033[33;"
#define FBLUE       "\033[34;"
#define FPURPLE     "\033[35;"
#define D_FGREEN    "\033[6;"
#define FWHITE      "\033[7;"
#define FCYAN       "\x1b[36m"

//background color
#define BBLACK      "40m"
#define BRED        "41m"
#define BGREEN      "42m"
#define BYELLOW     "43m"
#define BBLUE       "44m"
#define BPURPLE     "45m"
#define D_BGREEN    "46m"
#define BWHITE      "47m"

//end color
#define NONE        "\033[0m"


int mod(int a, int b) {
	/*Returns a%b*/
	if(b < 0)
		return mod(a, -b);
	int ret = a % b;
	if(ret < 0)
		ret+=b;
	return ret;
}

void imprime_pista() {
	int i, j, k;
	int num_digitos;
	num_digitos = conta_digitos(velodromo->total_ciclistas);
	for (i = 0; i < 10; i++) {
		for (j = 0; j < velodromo->tamanho; j++) {
			if (velodromo->circuito[i][j]) {
				for (k = num_digitos - conta_digitos(velodromo->circuito[i][j]); k > 0; k--)
					printf(FBLACK BWHITE " ");
				printf(FRED BWHITE " %d "NONE, velodromo->circuito[i][j]);
			}
			else {
			
					for (k = num_digitos - 1; k > 0; k--)
						printf(FBLACK BWHITE " ");
					printf(FBLACK BWHITE " - ");
			}
			if (j == velodromo->tamanho - 1)
				printf(""NONE);
		}
		printf("\n");
	}
	printf("\n\n");
}

void imprime_placar() {
	int i;
	printf("PLACAR - (id, pontos):\n");
	for (i = 0; i < velodromo->total_ciclistas; i++)
		printf("(%d, %d) ", meu_placar->ranking[i]->id, meu_placar->pontos[i]);
	printf("\nFIM DO PLACAR\n\n");
}

void aumenta_relogio() {
	if (velodromo->v_max != 90) relogio += 60;
	else relogio += 20;

	// Debug
	if (debug) {
		pthread_mutex_lock(&mutex_pista);
		imprime_pista();
		pthread_mutex_unlock(&mutex_pista);
	}
}

int conta_digitos(int a) {
	int num_digitos;
	for (num_digitos = 0; a > 0; num_digitos++)
		a = a/10;
	return num_digitos;

}