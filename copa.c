#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int *criarAlbum(int n);//gera o vetor din�mico 670 posicoes
void inicializa(int *p, int n);//grava 0 nas posi��es do vetor
int figurinha(int *palbum, int n);//gera 5 numeros aleatorios --> cola no album
void desaloca(int **pp);
int contarFigurinhasNR(int *palbum, int n);
void criarAlbum2(int **palbum,int n);

int main()
{
	int op=1, *album=NULL, n=670, cf=0,nrepetidas=0;
	float gastos=0;
	//int *vetp[5];
	while(op) //(op!=0)
	{
		//figurinhas reptidas
		//figurinhas NAO coladas
		//quando completei o album
		printf("\n1 - Comprar album");
		printf("\n2 - Colar Figurinha");
		printf("\n3 - Total de figurinhas");
		printf("\n4 - Total de figurinhas nao repetidas");
		printf("\n5 - Gastos");
		printf("\n6 - Desalocar");
		printf("\n0 - Sair");
		//figurinha();
		printf("\nInforme opcao:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					if(album) //if(album!=NULL)
					   printf("\nVc ja comprou o album");
					else
					{
						//album = criarAlbum(n);
						criarAlbum2(&album,n);
						inicializa(album,n);
						gastos = gastos+12;
						//printf("%d",*album);
					}
				}break;
			case 2:
				{
					if(album) ///se o album existe if(album!=NULL)
					{
						figurinha(album, n);
						gastos = gastos + 4;
						cf = cf + 5;
					}
					else
					{
						printf("\nNao existe album!");
					}
				}break;
			case 3:
				{
					printf("\nTotal de figurinhas compradas %d", cf);
				}break;
			case 4:
				{
					if(album)
					{
						nrepetidas = contarFigurinhasNR(album, n);
						printf("\nFigurinhas nao repetidas %d", nrepetidas);
					}
					else
					    printf("Nao existe album!");
					
				}break;
			case 5: printf("\nGastos = %f",gastos);break;
			case 6:
				{
				  desaloca(&album);
				  gastos=0;
				  cf=0;
				  //op=0;	
				}break;
			
		}
	}
}

int figurinha(int *palbum, int n) 
{ 
	int x,i;
	srand(time(NULL));  
	for(i=1; i<=5; i++)
	{
		x = rand() % 670; /* x vai receber um valor entre 0 e 670 */ 
		printf("\n%d", x);
		*(palbum+x) = *(palbum+x) + 1;
		//palbum[x]++;
		//(*(palbum+x))++;
	}
}

int *criarAlbum(int n)
{
	int *p=NULL;
	p = (int *)malloc(sizeof(int)*n);
	if(p==NULL) //(!p)
	  printf("\nNao tem memoria alocada!");
	return(p);
}

void inicializa(int *p, int n)
{
	int i;
	if(p)//(p!=NULL)
	{
		for(i=0; i<n; i++)
		{
			*(p+i) = 0;
			//p[i]=0;
		}
	}
}

void desaloca(int **pp)
{
	if(*pp) //if(pp!=NULL)
	{
		free(*pp);
		*pp = NULL;
	}
	else
	{
		printf("\nNao existe album!");
	}
}

int contarFigurinhasNR(int *palbum, int n)
{
	int cont=0, i=0;
	if(palbum)
	{
		for(i=0; i<n; i++)
		{
			if(*(palbum+i)==1)
			{
				printf("\n%d",i);
				cont++;
			}
		}
	}
	else
		printf("\nNao existe album!");
	return(cont);
}

void criarAlbum2(int **palbum,int n)
{
	if(*palbum==NULL)
	{
		*palbum=(int *)malloc(sizeof(int)*n);
	}
	else
	  printf("\nJa existe album!");
}

