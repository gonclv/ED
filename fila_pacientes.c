#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct paciente{
	char nome[15];
	int senha, idade;
	struct paciente *prox;
}Tpaciente;

int i;

Tpaciente *alocaNo(int k, char nome[], int i);
//inser��o no final da fila
void enfileirar(Tpaciente **p, char nome[], int idade, int senha);
void imprimeLista(Tpaciente *paux);
//remo��o no in�cio da fila
void desenfileirar(Tpaciente **pinicio);
Tpaciente *buscarFila(Tpaciente *p, Tpaciente **anterior);
//insere pilha
void empilhar(char nome[], int senha, int idade, Tpaciente **p);
//tira da fila e coloca na pilha
//remo��o no in�cio da pilha
void desempilhar(Tpaciente **ptopo);

int main()
{
	Tpaciente *inicio=NULL, *fim=NULL, *anterior=NULL, *topo=NULL;
	int op=1, idade;
	char nome[15]; 
	i=1;
	while(op!=7)
	{
		printf("\n1 - Insere fila");
		printf("\n2 - Atendimento medico - retira fila");
		printf("\n3 - Imprime");
		printf("\n4 - Mover prioritario");//priorit�rio acima de 70 anos
		printf("\n5 - Fila para pilha");
		printf("\n6 - Pilha para fila");
		printf("\n7 - Sair");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					printf("\nInforme nome:");
					fflush(stdin);
					scanf("%[^\n]",&nome);
					printf("\nInforme idade:");
					scanf("%d",&idade);
					enfileirar(&fim, nome, idade,i);
					i++;
					if(inicio==NULL)
					   inicio=fim;
				}break;
			case 2: 
			{
				desenfileirar(&inicio);
				if(inicio==NULL)
				  {
				  	fim=inicio;
				  	//i=1; zerar contador da fila
				   } 
			}break;
			case 3: imprimeLista(inicio);break;
			case 4:
				{
					Tpaciente *prioritario;
					prioritario = buscarFila(inicio,&anterior);
					if(prioritario==NULL)
					   printf("\nNao tem prioritario!");
					else
					{
						if(prioritario!=inicio)
						{
							printf("\n%s", prioritario->nome);
							anterior->prox = prioritario->prox;
							prioritario->prox = inicio;
							inicio = prioritario;
						}
							
					}
				}break;
			case 5:
				{
					while(inicio!=NULL)
					{
						empilhar(inicio->nome, inicio->senha, inicio->idade,&topo);
						desenfileirar(&inicio);
					}
					if(inicio==NULL)
					{
						printf("\ninicio NULL");
						fim=inicio;
					}
					imprimeLista(topo);
				}break;
			case 6:
				{
					if(topo==NULL) 
						printf("\nPilha vazia!");
					while(topo!=NULL)
					{
						enfileirar(&fim, topo->nome, topo->idade, topo->senha); //problema na senha
						//faltou atribuir inicio=fim para o 1o elemento da fila
						if(inicio==NULL)
					   		inicio=fim;
						desempilhar(&topo);
					}
					imprimeLista(inicio);
				}break;
		}
	}
}

Tpaciente *alocaNo(int k, char nome[], int i)
{
	Tpaciente *p;
	p = (Tpaciente *)malloc(sizeof(Tpaciente));
	if(p==NULL) return NULL;
	else
	{
		strcpy(p->nome, nome);
		p->senha = i;
		p->idade = k;
		p ->prox = NULL;
		return p;
	}
}

void enfileirar(Tpaciente **pfim, char nome[], int idade, int i)
{
	Tpaciente *novo=NULL;
	novo = alocaNo(idade, nome,i);
	if(*pfim!=NULL)
	   (*pfim)->prox = novo;
	*pfim = novo;	
}
//remo��o no inicio
void desenfileirar(Tpaciente **pinicio)
{
	Tpaciente *aux;
	if(*pinicio==NULL)
	{
		printf("\nFila vazia!");
		return;
	}
	aux = *pinicio;
	*pinicio = (*pinicio)->prox;
	free(aux);
	aux=NULL;
}

void imprimeLista(Tpaciente *paux)
{
	if(paux==NULL) printf("\nLista vazia!");
	while(paux!=NULL)
	{
		printf("\n%s", paux->nome);
		printf("\n%d", paux->senha);
		paux = paux->prox;
	}
}

Tpaciente *buscarFila(Tpaciente *p, Tpaciente **anterior)
{
	if(p==NULL) return NULL;
	while(p!=NULL)
	{
		
		if(p->idade>=70)
			return p;
		*anterior = p;
		p=p->prox;
	}
}

//insere no in�cio
void empilhar(char nome[], int senha, int idade, Tpaciente **p)
{
	Tpaciente *novo;
	novo = alocaNo(idade, nome,senha);
	if(novo==NULL) return ;
	else
	{
		//novo->senha = senha; alterei as fun��es passando i como par�metro para manter sa senha
		novo->prox = *p;
		*p = novo;
	}
}
//remo��o no inicio
void desempilhar(Tpaciente **pinicio)
{
	Tpaciente *aux;
	if(*pinicio==NULL)
	{
		printf("\nPilha vazia!");
		return;
	}
	aux = *pinicio;
	*pinicio = (*pinicio)->prox;
	free(aux);
	aux=NULL;
}
