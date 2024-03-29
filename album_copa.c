#include <time.h>
#include <stdio.h>
#include <stdlib.h>

float gastos = 0;

int *criarAlbum(int *pAlbum, int n);
void inicializar(int *pAlbum, int n);
int figurinhas(int *pAlbum);

int main() {
	int op = 1, *album = NULL, n;
	//int *vetAlbum[5];
	printf("Informe quantidade de figurinhas: ");
	scanf("%d", &n);

	while(op) { //while(op!=0)
		printf("Digite uma opção:\n");
		printf("1 - Comprar álbum\n");
		printf("2 - Comprar figurinhas\n");
		printf("5 - Verificar gastos\n");
		printf("6 - Finalizar\n");
		scanf("%d", &op);
		
		switch(op) {
			case 1: {
				if (album)
					printf("Você já comprou um álbum\n");
				else {
					album = criarAlbum(album, n);
					inicializar(album, n);
					gastos = gastos + 12;
				}
			} break;
			case 2: {
				figurinhas(album);
				if(album)
					gastos = gastos + 4;
			} break;
			case 5: {
				printf("Gastos = %.2f\n", gastos);
			} break;
			case 6: {
				//desalocar();
			} break;
		}
	}
		//figurinha();
		//printf("\n1- Gerar mais 5 numeros 0-Sair");
		//scanf("%d",&op);
	}

int *criarAlbum(int *pAlbum, int n) {
	int *p = NULL;

	if (pAlbum == NULL) {
		p = (int *) malloc(sizeof(int) * n);
		if(p == NULL)
			printf("Deu pau :(\n");
		else
			printf("Álbum comprado com sucesso!\n");
		return p;
	}
	else {
		printf("Você já comprou um álbum\n");
		return pAlbum;
	}
}

void inicializar(int *pAlbum, int n) {
	for (int i = 0; i < n; i++) {
		*(pAlbum + i) = 0;
	}
}
/*
void alocaAlbum(int n, int ) {
	int *p = NULL;
	p = (int *) malloc(sizeof(int) * n);
}
*/
int figurinhas(int *pAlbum) 
{ 
	int x,i;
	if(pAlbum) {
		srand(time(NULL));  
		for(i=1; i<=5; i++)
		{
			x = rand() % 670; /* x vai receber um valor entre 0 e 670 */ 
			printf("%d\n", x);
			++*(pAlbum + x);
		}	
	}
	else {
		printf("Precisa adquirir o álbum\n");
	}
}

void desalocar(int **pAlbum) {
	if (*pAlbum == NULL)
		printf("Não há álbum\n");
	else {
		free(*pAlbum);
		*pAlbum = NULL;
	}
}
