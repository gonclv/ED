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
	return novo; //devolve o endere�o do n� para a main() / algu�m??
}

void insereInicio(int k,TNo **paux) //push
{
	TNo *novo;
	novo = alocaNo(k);
	novo->prox = *paux;
	*paux = novo;
	
}

void imprimeLista(TNo *paux)//imprime pilha
{
	while(paux!=NULL)
	{
		printf("\n%d", paux->chave);
		paux = paux->prox;
	}
	
}

void removeInicio(TNo **paux)//pop
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
	TNo *inicio=NULL, *final=NULL;
	int op=1,chave;
	while(op!=4)
	{
		printf("\n1 - Insere");
		printf("\n2 - Retira");
		printf("\n3 - Imprime");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
				  {
				    printf("\nInforme valor:");
				    scanf("%d",&chave);
					insereInicio(chave,&inicio);
				  }break;
			case 2:
				{
					if(inicio==NULL)
					   printf("\nLista vazia!");
					else
					   {
					   	   removeInicio(&inicio);
					   }
				}break;
			case 3:
				{
				  
				  imprimeLista(inicio);	
				}break;
			
		}
   }
}
}