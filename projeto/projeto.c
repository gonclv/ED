#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Pessoa{
    char nome[15];
    int idade, dose1, dose2; //considere valor 1 para vacinado e 0 não vacinado
    char vacina[10]; //nome da vacina que tomou na 1ª dose
    struct Pessoa *prox;
} TPessoa;

TPessoa *aloca(char nome[15], int idade, int dose1, int dose2, char vacina[10]) {
    TPessoa *no;
    no = (TPessoa *) malloc(sizeof(TPessoa));
    if(no == NULL) return NULL;

    strcpy(no->nome, nome);
    no->idade = idade;
    no->dose1 = dose1;
    no->dose2 = dose2;
    strcpy(no->vacina, vacina);
    no->prox = NULL;
    
    return no;
}

void insere(TPessoa **p, TPessoa **p2) {
    int idade, dose1,dose2;
    char nome[15], vacina[10];

    FILE *arq1 = NULL;
    FILE *arq2 = NULL;
    arq1 = fopen("postoY.txt", "r");
    arq2 = fopen("postoZ.txt", "r");

    if(arq1 == NULL || arq2 == NULL) {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    else {
        while(!feof(arq1)) {
            fscanf(arq1, "%s %d %d %d %s", &nome, &idade, &dose1, &dose2, &vacina);
            //printf("%s %d %d %d %s\n", nome, idade, dose1, dose2, vacina);
            TPessoa *novo;
            novo = aloca(nome, idade, dose1, dose2, vacina);
            if(novo == NULL) return;
            novo->prox = *p;
	        *p = novo;
        }

        while(!feof(arq2)) {
            fscanf(arq2, "%s %d %d %d %s", &nome, &idade, &dose1, &dose2, &vacina);
            //printf("%s %d %d %d %s\n", nome, idade, dose1, dose2, vacina);
            TPessoa *novo2;
            novo2 = aloca(nome, idade, dose1, dose2, vacina);
            if(novo2 == NULL) return;
            novo2->prox = *p2;
	        *p2 = novo2;
        }
    }

    fclose(arq1);
    fclose(arq2);
}

TPessoa* unifica(TPessoa *p1, TPessoa *p2) {
	TPessoa *no, *no2, *lista3 = NULL, *aux;
	int compara;
	
	if(p1) //p!=NULL
	{
		while(p1!=NULL)
		{
			no = aloca(p1->nome, p1->idade, p1->dose1, p1->dose2, p1->vacina);
			if(no == NULL) return NULL;
			no->prox = lista3;
			lista3 = no;
			p1 = p1->prox;
		}
	}

	
	
	if(p2) //p!=NULL
	{
		while(p2!=NULL)
		{
			aux = lista3;
			while(aux!=NULL){
			
			compara = strcmp(p2->nome, aux->nome);
			
			if (compara == 0) {
				
					if(p2->dose2 == 1 || aux->dose2 == 1) {
						aux->dose1 = 1;
						aux->dose2 = 1;
						break;
					}
			}
			aux = aux->prox;
		}
			if(compara != 0) {
				no2 = aloca(p2->nome, p2->idade, p2->dose1, p2->dose2, p2->vacina);
				if(no2 == NULL) return NULL;
				no2->prox = lista3;
				lista3 = no2;
			
		}
		p2 = p2->prox;
	}
}

	return lista3;
}

void imprimeLista(TPessoa *p)
{
	//assert(p);
	if(p) //p!=NULL
	{
		while(p!=NULL)
		{
			printf("%s %d %d %d %s\n", p->nome, p->idade, p->dose1, p->dose2, p->vacina);
			p = p->prox;	
		}
	}
	else
		printf("\nLista vazia!");
}

TPessoa *busca(TPessoa *lista3) {
	if(lista3 == NULL) {
		printf("Lista vazia\n");
		return NULL;
	}

 	TPessoa *aux = lista3, *no;
	int confirmacao, confirmacao2, idade, compara;
	char nome[15], vacina[10];
	printf("Digite o nome da pessoa:\n");
	scanf("%s", &nome);

	while(aux!=NULL) {

		compara = strcmp(aux->nome, nome);
		if(compara == 0) {
			if(aux->dose1 == 1 && aux->dose2 == 0) {
				printf("Tomou a dose 1: %s\n", aux->vacina);
				printf("Confirme se a dose 2 foi aplicada (1 - Sim, 0 - Não)\n");
				scanf("%d", &confirmacao);
				if(confirmacao == 1) {
					aux->dose2 = 1;
				}
				else if(confirmacao == 0) {
					printf("Dose nao aplicada\n");
				}
				else {
					printf("Opcao invalida\n");
				}
			}
			else if(aux->dose1 == 1 && aux->dose2 == 1) {
				printf("As duas doses ja foram aplicadas\n");
			}
			break;
		}
		else aux = aux->prox;
	}
	if(compara != 0) {
		if(lista3) {
			printf("Digite a idade: \n");
			scanf("%d", &idade);
			printf("Confirme se a dose 1 foi aplicada (1 - Sim, 0 - Não)\n");
			scanf("%d", &confirmacao2);
			if(confirmacao2 == 1) {
				printf("Digite a vacina aplicada:\n");
				scanf("%s", &vacina);
				no = aloca(nome, idade, 1, 0, vacina);
				if(no == NULL) return NULL;
				no->prox = lista3;
				lista3 = no;
			}
			else if(confirmacao2 == 0) {
				printf("Dose nao aplicada\n");
			}
			else {
				printf("Opcao invalida\n");
			}
		}
	}

	return lista3;
}

void desaloca(TPessoa **p) {
	TPessoa *aux;
	if(*p == NULL) return;
	aux = *p;
	*p = (*p)->prox;
	free(aux);
	aux = NULL;
}

void sair(TPessoa *lista3) {
	if(lista3 == NULL) {
		printf("Lista vazia\n");
		return;
	}

	TPessoa *aux;
	aux = lista3;

	FILE *arq = NULL;
	arq = fopen("unificadoZY.txt", "w");

	if(arq == NULL) {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    else {
    	while(aux!=NULL){
   			fprintf(arq, "%s %d %d %d %s\n", aux->nome, aux->idade, aux->dose1, aux->dose2, aux->vacina);
            aux = aux->prox;
        }
    }

    fclose(arq);
}

void main() {
    int i = 0,  op, op2;
    char nome;
    TPessoa *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;

    while(op!=5) {
		printf("\n1 - Unificar");
		printf("\n2 - Buscar");
		printf("\n3 - Imprimir");
		printf("\n4 - Desalocar");
		printf("\n5 - Sair");
		printf("\nInforme opcao:");
		scanf("%d",&op);
		setbuf(stdin, NULL);

		switch(op) {
			case 1: {
				if(lista3 == NULL) {
					insere(&lista1, &lista2);
					lista3 = unifica(lista1, lista2);
				}
				else {
					printf("Lista ja existe\n");
				}
				
			} break;
			case 2: 
			{
				lista3 = busca(lista3);
			} break;
			case 3: {
				printf("1 - Imprimir lista 1\n");
				printf("2 - Imprimir lista 2\n");
				printf("3 - Imprimir lista 3\n");
				scanf("%d", &op2);
				setbuf(stdin, NULL);

				switch (op2) {
					case 1: imprimeLista(lista1); break;
					case 2: imprimeLista(lista2); break;
					case 3: imprimeLista(lista3); break;
					default: printf("Opcao invalida\n"); break;
				}
			} break;
			case 4: {
				if(lista1 == NULL) {
					printf("Lista 1 vazia\n");
				}
				else {
					while(lista1!=NULL)
					desaloca(&lista1);
				}
				if(lista2 == NULL) {
					printf("Lista 2 vazia\n");
				}
				else {
					while(lista2!=NULL)
					desaloca(&lista2);
				}
				if(lista3 == NULL) {
					printf("Lista 3 vazia\n");
				}
				else {
					while(lista3!=NULL)
					desaloca(&lista3);
				}
				
			} break;
			case 5: {
				sair(lista3);
				while(lista1!=NULL)
					desaloca(&lista1);
				while(lista2!=NULL)
					desaloca(&lista2);
				while(lista3!=NULL)
					desaloca(&lista3);
			} break;
			default: {
				printf("\nOpcao invalida");
			} break;
		}
    }
}
