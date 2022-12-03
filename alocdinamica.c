#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define tam 670

int *criarAlbum(int n);
void inicializar(int *pAlbum, int n);
int comprarFigurinhas(int *pAlbum, int n);

int main() {
	int op = 1, *album = NULL;

	while(op) { //while(op!=0)
		printf("Digite uma opção:\n");
		printf("1 - Comprar álbum\n");
		printf("2 - Comprar pacote de figurinhas\n");
		scanf("%d", &op);
		
		switch(op) {
			case 1: {
				if(album) //if(album != NULL)
					printf("Você já comprou um álbum.\n");
				else {
					album = criarAlbum(tam);
					inicializar(album, tam);
				}
			} break;
			case 2: {
				if(album) { //if(album!=NULL)
					comprarFigurinhas(album, tam);
				}
				else {
					printf("O álbum não foi comprado.\n");
				}

			} break;
		}
	}
}

int *criarAlbum(int n) {
	int *p = NULL;
	p = (int *) malloc(sizeof(int) * n);

	if(p == NULL) //if(!p)
		printf("Deu bosta :(\n");
	else
		printf("Álbum comprado com sucesso!\n");
	return p;
}

void inicializar(int *p, int n) {
	if (p) //if(p != NULL)
		for(int i = 0; i < n; i++)
			*(p + i) = 0;
}

int comprarFigurinhas(int *pAlbum, int n) {
	int x;
	srand(time(NULL));
	for(int i=1; i<=5; i++)
	{
		x = rand() % (n - 1); /* x vai receber um valor entre 0 e 670 */ 
		++*(pAlbum + x); //*(pAlbum + x) = *(pAlbum + x) + 1
	}	
}