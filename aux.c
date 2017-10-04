#include "aux.h"

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
	int i, j;
	printf("PISTA:\n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < velodromo->tamanho; j++)
			printf("%d ", velodromo->circuito[i][j]);
		printf("\n");
	}
	printf("FIM DA PISTA\n\n");
}

void imprime_placar() {
	int i;
	printf("PLACAR - (id, pontos):\n");
	for (i = 0; i < velodromo->total_ciclistas; i++)
		printf("(%d, %d) ", meu_placar->ranking[i]->id, meu_placar->pontos[i]);
	printf("\nFIM DO PLACAR\n\n");
}