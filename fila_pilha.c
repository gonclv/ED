#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	int chave;
	//campos....
	struct no *prox;
}TNo;

TNo *alocaNo(int k)
{
	TNo *novo;
	novo = (TNo *)malloc(sizeof(TNo));
	if (novo == NULL) return NULL;
	novo->chave = k;
	novo->prox = NULL;
	return novo; 
}
//FILA
//enfileirar --> inserimos no final
void enfileirar(TNo **fim, int k)
{
	TNo *novo;
	novo = alocaNo(k);
	if (novo==NULL) return;
	if(*fim!=NULL)
		(*fim)->prox = novo;
	*fim = novo;
}
//desenfileirar --> remove no inicio
void desenfileirar(TNo **p)
{
	TNo *aux;
	if(*p==NULL) 
	{
		printf("\nLista vazia!");
		return;
	}
	aux = *p;
	*p = (*p)->prox;
	free(aux);
	aux=NULL;
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
		printf("\n%d", p->chave);
		p = p->prox;
	}
}

//desempilhar --> insere no in�cio
void empilhar(int k,TNo **paux) //push
{
	TNo *novo;
	novo = alocaNo(k);
	novo->prox = *paux;
	*paux = novo;
	
}
//desempilhar --> remove no in�cio
void desempilhar(TNo **paux)//pop
{
   TNo *aux= *paux;
   if(*paux == NULL) 
   {
   	printf("\nLista vazia");
   	return ;
   }
   if((*paux)->prox!=NULL)
     {
        *paux = (*paux)->prox;
        free(aux);
       // return paux;
	 }
    else
    {
    	free(aux);
    	*paux=NULL;
		return ;
	}   
}


int main()
{
	TNo *inicio=NULL, *fim=NULL, *iniciopilha=NULL;
	int op=1, n;
	while(op!=8)
	{
		printf("\nInforme \n1-Enfileirar \n2-Desenfileirar\n3-Imprimir\n4-Empilhar\n5-Desempilhar\n6-FilaPilha\n7-PilhaFila\n8-Sair\n:");
		scanf("%d",&op);
		if(op==1)
		{
			printf("\nValor:");
			scanf("%d",&n);
			enfileirar(&fim,n);
			if(inicio==NULL)
	   			inicio=fim;
		}
		if(op==2)
		{
			desenfileirar(&inicio);
			if(inicio==NULL)
			   fim=inicio; //fim=NULL;
		}
		if(op==3)
		{
			printf("\nFila\n");
			imprimeLista(inicio);
			printf("\nPilha\n");
			imprimeLista(iniciopilha);
		}
		if(op==4)
		{
			printf("\nInforme valor:");
			scanf("%d",&n);
			empilhar(n,&iniciopilha);
		}
		if(op==5)
		{
			if(iniciopilha==NULL)
			   printf("\nLista vazia!");
			else
			   {
			   	   desempilhar(&iniciopilha);
			   }
		}
		if(op==6)
		{
			//Fila para a Pilha
			//desenfileirar --> empilhar
			while(inicio!=NULL)
			{
				empilhar(inicio->chave, &iniciopilha);
				desenfileirar(&inicio);
			}
			fim = inicio;
		}
		if(op==7)
		{
			//Pilha para a Fila
			//desempilhar --> enfileirar
			while(iniciopilha!=NULL)
			{
				enfileirar(&fim, iniciopilha->chave);
				if(inicio==NULL)
				   inicio=fim;
				desempilhar(&iniciopilha);
			}
		}
	}
}
