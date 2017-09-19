//Conterá a struct pista e os métodos da pista

typedef struct {
	ciclistas *pista[10];
	int total_ciclistas;
} pista;

//Recebe a pista e o tamanho. Aloca e inicializa a pista.
int cria_pista(pista *p, int d);

int destroi_pista(pista *p);

//muda a posição do ciclista (na pista tbm).
void pedala(ciclista *c);

//realiza ultrapassagem com o ciclista recebido.
void ultrapassa(ciclista *c);

//Recebe um índice da pista e retorna o número de ciclistas naquela posição
int numero_de_ciclistas(int d);

