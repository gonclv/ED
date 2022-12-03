#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;
}TNo;

/*typedef struct cabeca{
	struct no *inicio;
	struct no *fim;
}TCabeca;*/

void insereFim(TNo **fim, int k)
{
	TNo *novo;
	novo =(TNo *)malloc(sizeof(TNo));
	if (novo==NULL) return;
	novo->valor=k;
	novo->prox = NULL;
	if(*fim!=NULL)
		(*fim)->prox = novo;
	*fim = novo;
}

void imprimeLista(TNo *p)
{
	if(p==NULL)
	{
		printf("\nLista vazia!");
		return;
	}
	while(p!=NULL)
	{
		printf("\n%d", p->valor);
		p = p->prox;
	}
}

void removeInicio(TNo **p)
{
	TNo *aux;
	if(*p==NULL) {
		printf("\nLista vazia!");
		return;
	}
	aux = *p;
	*p = (*p)->prox;
	free(aux);
	aux=NULL;
}

void main()
{
	TNo *inicio=NULL, *fim=NULL;
	int op=1, n;
	while(op!=4)
	{
		printf("\nInforme \n1-Inserir \n2-Retirar\n3-Imprimir\n4-Sair\n:");
		scanf("%d",&op);
		if(op==1)
		{
			printf("\nValor:");
			scanf("%d",&n);
			insereFim(&fim,n);
			if(inicio==NULL)
	   			inicio=fim;
		}
		if(op==2)
		{
			removeInicio(&inicio);
			if(inicio==NULL)
			   fim=inicio; //fim=NULL;
		}
		if(op==3)
		{
			imprimeLista(inicio);
		}
	}
}