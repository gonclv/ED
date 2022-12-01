#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct No {
	int chave;
	int valorQualquer;
	struct No *prox;
} TipoNo;

typedef struct NoDuplEnc { 
     int chave; 
     struct no *ant; 
     struct no *prox; 
 } TNoDuplEnc;

TipoNo *alocaNoSimples(int k)
{
	TipoNo *no = (TipoNo *) malloc(sizeof(TipoNo));
	if (no == NULL) return NULL;
	no->chave = k;
	no->prox = NULL;
	return no;
}

void insereInicioSimples(TipoNo **prim, int k)
{ 
  assert(prim);  
  TipoNo* noAux = alocaNoSimples(k);
  if (noAux == NULL) return;//return NULL;
  noAux->prox = *prim;
  *prim = noAux;
}

void insereFinalSimples(TipoNo *prim, int k)
{ 
  assert(prim); 
  TipoNo* pa=prim; 
  TipoNo* noAux = alocaNoSimples(k);
  if (noAux == NULL) return;
  while(pa->prox!=NULL)
    {
    	pa = pa->prox;
	}
 
  pa->prox = noAux;
}

void imprimeListaSimples(TipoNo *prim)
{
	while(prim!=NULL)
	{
		printf("%d\n", prim->chave);
		prim = prim->prox;
	}
}

void removePrimeiroSimples(TipoNo **prim)
{
  assert(prim);
  if (*prim == NULL) return;
  TipoNo *aux = *prim;
  *prim = (*prim)->prox;
  free(aux);
}

void removeUltimoSimples(TipoNo **prim) {
  	assert(prim);
  	TipoNo *paux=*prim, *pant=*prim;
  	if (*(prim)== NULL) printf("\nLista vazia!");
  	if ((*(prim))->prox == NULL) {
    	free(*prim);
		*prim = NULL;	
  	}
  	else {
  	  while(paux->prox!=NULL) {
  		pant = paux;
		paux = paux->prox;
	  }
	  free(paux);
	  pant->prox=NULL;
  }
}

TipoNo *buscaNoSimples(TipoNo *no, int chave) {
	while(no!=NULL) {
		if(no->chave == chave) return no;
		else no = no->prox;
	}
	return NULL;
}

TipoNo *criaListaCabeca() {
	TipoNo *cabeca = (TipoNo *) malloc(sizeof(TipoNo));
	if(!cabeca) return NULL;
	cabeca->chave = -1;
	cabeca->valorQualquer = -1;
	cabeca->prox = NULL;
	return cabeca;
}

TipoNo *alocaNoCabeca(int chave) {
	TipoNo *no = (TipoNo *) malloc(sizeof(TipoNo));
	if(!no) return NULL;
	no->chave = chave;
	no->valorQualquer = chave;
	no->prox = NULL;
	return no;
}

TipoNo *insereInicioNoCabeca(TipoNo *cabeca, int chave) {
	assert(cabeca);
	TipoNo *no = alocaNoCabeca(chave);
	if(!no) return NULL;
	no->prox = cabeca->prox;
	return no;
}

void atualizaValorCabeca(TipoNo *cabeca, int novoValor) {
	assert(cabeca);
	if(!cabeca->prox) return;
	cabeca->prox->valorQualquer = novoValor;
}

void removePrimeiroNoCabeca(TipoNo *cabeca) {
	assert(cabeca);
	TipoNo *aux = cabeca->prox;
	if(!aux) return;
	cabeca->prox = aux->prox;
	free(aux);
	aux = NULL;
}

TipoNo *pesquisaNoCabeca(TipoNo *cabeca, int chave) {
	assert(cabeca);
	TipoNo *lista = cabeca->prox;

	if(!lista) {
		printf("Lista vazia\n");
		return NULL;
	}

	while(lista) {
		if(lista->chave == chave) return lista;
		lista = lista->prox;
	}

	printf("Elemento nao encontrado\n");
	return NULL;
}

TipoNo *insereFimCabeca(TipoNo *cabeca, int chave) {
	assert(cabeca);
	TipoNo *no = alocaNoCabeca(chave);
	if(!no) return NULL;
	
	while(cabeca->prox != NULL) cabeca = cabeca->prox;
	cabeca->prox = no;
	return no;
}

void imprimeListaCabeca(TipoNo *cabeca) {
	assert(cabeca);
	TipoNo *lista = cabeca->prox;

	if(lista)
		while(lista) {
			printf("%d %d\n", lista->chave, lista->valorQualquer);
			lista = lista->prox;	
		}
	else
		printf("Lista vazia!\n");
}

void insereCircular(TipoNo **p, int info)
{
    assert(p);	
    if(*p == NULL) //if(!(*p)) --> nao tem ninguem na lista
    {	
        *p = (TipoNo *) malloc(sizeof(TipoNo));
         if(*p != NULL) //if(*p)
          {	
			(*p)->chave = info;
			(*p)->prox = *p;
          }	
   }
   else //ja tem alguem na lista
   {
   	    TipoNo *aux = (TipoNo *) malloc(sizeof(TipoNo));
        if (aux == NULL) return;
        aux->chave = info;		
        aux->prox = (*p)->prox;	
        (*p)->prox = aux;	//insere no inicio
        //(*p)=(*p)->prox; //*p=aux; --> final
    }
}

void removeCircular(TipoNo **p)
{
    assert(p);	
    if(*p == NULL) return;	
    TipoNo *pPrim = (*p)->prox;
    TipoNo *pPenult = (*p)->prox;
    if(pPrim->prox != pPrim)
    {
       while(pPenult->prox != *p)
       {
			pPenult = pPenult->prox;
       }
	  free(*p);
      *p = pPenult;
       pPenult->prox = pPrim;
     } //if
    else
     {
		free(*p);
		*p = NULL;
     }
}	

void imprimeCircular(TipoNo *p)
{

	if (p==NULL) printf("\nLista Vazia!");
	TipoNo *aux=p->prox;
	do
	{
		printf("\n%d", aux->chave);
		aux = aux->prox;
	}while(p->prox!=aux); //while(p!=aux);
//	printf("\n%d", p->chave);
}

void insereUltimoRecursivo(TipoNo **no, int k)
{
	if(*no==NULL) //lista vazia ou ultimo no->prox e null
	{
		*no = (TipoNo *)malloc(sizeof(TipoNo));
		if(*no==NULL) return;
		(*no)->chave = k;
		(*no)->prox = NULL;
	}
	else
	{
		insereUltimoRecursivo(&((*no)->prox), k);	
	}
}

void imprimeLista(TipoNo *paux) //nao e recursivo
{
	if(paux==NULL) printf("\nLista vazia!");
	while(paux!=NULL)
	{
		printf("\n%d", paux->chave);
		paux = paux->prox;
	}
}

void imprimeListaRec(TipoNo *paux)//imprime recursivo
{
	if(paux==NULL) return;
	else
	{
		printf("\n%d", paux->chave);
		imprimeListaRec(paux->prox);
	}
}

void imprimeListaRec2(TipoNo *paux)//imprime recursivo ultimo primeiro
{
	if(paux==NULL) return;
	else
	{
		imprimeListaRec2(paux->prox);
		printf("\n%d", paux->chave);
	}
}

void removeNoRec(TipoNo **no)
{
	if(*no==NULL) return;
	removeNoRec(&(*no)->prox);
	free(*no);
	*no=NULL;
}

void insereFila(TipoNo **fim, int k)
{
	TipoNo *novo;
	novo =(TipoNo *)malloc(sizeof(TipoNo));
	if (novo==NULL) return;
	novo->chave=k;
	novo->prox = NULL;
	if(*fim!=NULL)
		(*fim)->prox = novo;
	*fim = novo;
}

void imprimeFila(TipoNo *p)
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

void removeFila(TipoNo **p)
{
	TipoNo *aux;
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

TipoNo *alocaNoPilha(int k)
{
	TipoNo *novo;
	novo = (TipoNo *)malloc(sizeof(TipoNo));
	if (novo == NULL) return NULL;
	novo->chave = k;
	novo->prox = NULL;
	return novo; //devolve o endere�o do n� para a main() / algu�m??
}

void inserePilha(int k, TipoNo **paux) //push
{
	TipoNo *novo;
	novo = alocaNoPilha(k);
	novo->prox = *paux;
	*paux = novo;
	
}

void imprimePilha(TipoNo *paux)//imprime pilha
{
	while(paux!=NULL)
	{
		printf("\n%d", paux->chave);
		paux = paux->prox;
	}
	
}

void removePilha(TipoNo **paux)//pop
{
   TipoNo *aux= *paux;
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

TNoDuplEnc *insereListaDuplEnc(TNoDuplEnc *p, int chave) { 
     //assert(p); 
     TNoDuplEnc *novo = (TNoDuplEnc *) malloc(sizeof(TNoDuplEnc)); 
     novo->chave = chave; 
     novo->prox = p; 
     novo->ant = NULL; 
  
     if(p!=NULL) { 
         p->ant = novo; 
     } 
  
     return novo; 
 }

void insereListaDuplEnc2(TNoDuplEnc **p, int chave) { 
     //assert(p); 
     TNoDuplEnc *novo = (TNoDuplEnc *) malloc(sizeof(TNoDuplEnc)); 
     novo->chave = chave; 
     novo->prox = *p; 
     novo->ant = NULL; 
  
     if(*p!=NULL) { 
         (*p)->ant = novo; 
     } 
  
     *p = novo; 
 }

TNoDuplEnc *buscaListaDuplEnc(TNoDuplEnc *p, int elem){ 
     TNoDuplEnc *paux;

	 printf("Chegou\n");
  
     for(paux = p; paux != NULL; paux = paux->prox) { 
		printf("Entrou\n");
         if(paux->chave == elem) return paux;
     } 

	printf("Saiu\n");
     return NULL; 
 }

void imprimeListaDuplEnc(TNoDuplEnc *p) { 
     TNoDuplEnc *paux; 
     if(p==NULL) { 
         printf("Lista vazia\n"); 
         return; 
     } 
  
     for(paux = p; paux != NULL; paux = paux->prox) { 
         printf("%d\n", paux->chave); 
     } 
 }

void imprimeListaDuplEncInv(TNoDuplEnc *p) { 
     TNoDuplEnc *paux = p; 
     if(p==NULL) { 
         return; 
     }

	 while(paux->prox != NULL) paux = paux->prox;
  
     while(paux != NULL) { 
         printf("%d\n", paux->chave);
		 paux = paux->ant;
     } 
 }

void desalocaDuplEnc(TNoDuplEnc **p) { 
     TNoDuplEnc *aux = *p; 
     if(p == NULL) { 
         printf("Lista vazia\n"); 
     } 
     else { 
         *p = (*p)->prox; 
         if(*p != NULL) { 
             (*p)->ant = NULL; 
         } 
         free(aux); 
     } 
 } 

void main() {
	int op1, op2, num, num2;

	do {
		printf("1 - Criar lista simples\n");
		printf("2 - Criar lista com cabeca\n");
		printf("3 - Criar lista circular\n");
		printf("4 - Criar lista recursiva\n");
		printf("5 - Criar lista dupl encadeada\n");
		printf("6 - Fila e pilha\n");
		printf("0 - Sair\n");
		printf("Digite uma opcao: ");
		scanf("%d", &op1);

		switch (op1) {
			case 1: {
				TipoNo *prim = NULL;

				do {
					printf("1 - Inserir no inicio\n");
					printf("2 - Imprimir lista\n");
					printf("3 - Remover do inicio\n");
					printf("4 - Inserir no final\n");
					printf("5 - Remover do final\n");
					printf("6 - Buscar na lista\n");
					printf("7 - Desalocar lista\n");
					printf("0 - Sair\n");
					scanf("%d", &op2);

					switch(op2) {
						case 1: {
							printf("Digite um numero: ");
							scanf("%d", &num);
							insereInicioSimples(&prim, num);
						} break;

						case 2: {
							imprimeListaSimples(prim);
						} break;

						case 3: {
							removePrimeiroSimples(&prim);
						} break;

						case 4: {
							insereFinalSimples(prim,890);
						} break;

						case 5: {
							removeUltimoSimples(&prim);
						} break;

						case 6: {
							TipoNo *pa = NULL;
							printf("Digite o elemento a ser buscado: ");
							scanf("%d", &num);
							pa = buscaNoSimples(prim,num);
							if(pa == NULL) printf("Valor nao encontrado\n");
  							else printf("Valor %d encontrado\n", pa->chave);
						} break;

						case 0:
						case 7: {
							while(prim!=NULL) removePrimeiroSimples(&prim);
						} break;

						default: {
							printf("Opcao invalida\n");
						} break;
					}
				} while(op2 != 0);
			} break;

			case 2: {
				TipoNo *cabeca = criaListaCabeca();

				do {
					printf("1 - Inserir no inicio\n");
					printf("2 - Atualizar valor\n");
					printf("3 - Remover do inicio\n");
					printf("4 - Imprimir lista\n");
					printf("5 - Buscar na lista\n");
					printf("6 - Inserir no fim\n");
					printf("7 - Desalocar lista\n");
					printf("0 - Sair\n");
					printf("Digite uma opcao: ");
					scanf("%d", &op2);

					switch(op2) {
						case 1: {
							printf("Digite o numero a ser inserido: ");
							scanf("%d", &num);
							cabeca->prox = insereInicioNoCabeca(cabeca, num);
						} break;

						case 2: {
							printf("Digite um numero: ");
							scanf("%d", &num);
							atualizaValorCabeca(cabeca, num);
						} break;

						case 3: {
							removePrimeiroNoCabeca(cabeca);
						} break;

						case 4: {
							imprimeListaCabeca(cabeca);
						} break;

						case 5: {
							TipoNo *busca;
							printf("Digite o elemento a ser procurado: ");
							scanf("%d", &num);
							busca = pesquisaNoCabeca(cabeca, num);
							if(busca) printf("Elemento encontrado: %d\n", busca->chave);
						} break;

						case 6: {
							TipoNo *no;
							printf("Digite o numero a ser inserido: ");
							scanf("%d", &num);
							no = insereFimCabeca(cabeca, num);
							if(no) printf("No inserido: %d\n", no->chave);
						} break;

						case 0:
						case 7: {
							while(cabeca->prox!=NULL) removePrimeiroNoCabeca(cabeca);
						} break;

						default: {
							printf("Opcao invalida\n");
						} break;
					}
				} while(op2 != 0);

			} break;

			case 3: {
				TipoNo *ultimo = NULL;

				do {
					printf("1 - Inserir\n");
					printf("2 - Imprimir\n");
					printf("3 - Remover\n");
					printf("0 - Sair\n");
					scanf("%d", &op2);

					switch(op2) {
						case 1: {
							printf("Digite o numero a ser inserido: ");
							scanf("%d", &num);
							insereCircular(&ultimo, num);
						} break;

						case 2: {
							imprimeCircular(ultimo);
						} break;

						case 3: {
							removeCircular(&ultimo);
						} break;

						case 0: break;

						default: {
							printf("Opcao invalida\n");
						} break;
					}
				} while(op2 != 0);
			} break;

			case 4: {
				TipoNo *prim = NULL;

				do {
					printf("1 - Inserir no final\n");
					printf("2 - Imprimir lista\n");
					printf("3 - Desalocar lista\n");
					printf("0 - Sair\n");
					scanf("%d", &op2);

					switch(op2) {
						case 1: {
							printf("Digite o numero a ser inserido: ");
							scanf("%d", &num);
							insereUltimoRecursivo(&prim, num);
						} break;

						case 2: {
							imprimeListaRec(prim);
							printf("\n");
							imprimeListaRec2(prim);
						} break;

						case 0:
						case 3: {
							removeNoRec(&prim);
						} break;

						default: {
							printf("Opcao invalida\n");
						} break;
					}
				} while(op2 != 0);
			} break;

			case 5: {
				TNoDuplEnc *prim = NULL, *achou;

				do {
					printf("1 - Inserir no inicio\n");
					printf("2 - Imprimir lista\n");
					printf("3 - Imprimir lista invertida\n");
					printf("4 - Remover do inicio\n");
					printf("5 - Buscar na lista\n");
					printf("6 - Desalocar lista\n");
					printf("0 - Sair\n");
					scanf("%d", &op2);

					switch(op2) {
						case 1: {
							printf("Digite dois numeros: ");
							scanf("%d %d", &num, &num2);
							prim = insereListaDuplEnc(prim, num); 
     						insereListaDuplEnc2(&prim, num2); 
						} break;

						case 2: {
							imprimeListaDuplEnc(prim); 
						} break;

						case 3: {
							imprimeListaDuplEncInv(prim);
						} break;

						case 4: {
							desalocaDuplEnc(&prim);
						} break;

						case 5: {
							printf("Digite um numero: ");
							scanf("%d", &num);
     						achou = buscaListaDuplEnc(prim, num); 
  
     						if(achou) { 
         						printf("%d encontado\n", achou->chave); 
     						} 
     						else { 
         						printf("Elemento nao encontrado\n"); 
     						} 
						} break;

						case 0:
						case 6: {
							while(prim!=NULL) desalocaDuplEnc(&prim);
						} break;

						default: {
							printf("Opcao invalida\n");
						} break;
					}
				} while(op2 != 0);
			} break;

			case 6: {
				TipoNo *inicio = NULL, *fim = NULL, *topo = NULL;

				do {
					printf("1 - Inserir na fila\n");
					printf("2 - Imprimir fila\n");
					printf("3 - Remover da fila\n");
					printf("4 - Inserir na pilha\n");
					printf("5 - Imprimir pilha\n");
					printf("6 - Remover da pilha\n");
					printf("7 - Fila para pilha\n");
					printf("8 - Pilha para fila\n");
					printf("9 - Desalocar tudo\n");
					printf("0 - Sair\n");
					scanf("%d", &op2);

					switch(op2) {
						case 1: {
							printf("Digite o numero a ser inserido: ");
							scanf("%d", &num);
							insereFila(&fim, num);
							if(inicio == NULL) inicio = fim;
						} break;

						case 2: {
							imprimeFila(inicio);
						} break;

						case 3: {
							removeFila(&inicio);
							if(inicio==NULL) fim = inicio; //fim=NULL;
						} break;

						case 4: {
							printf("Digite o numero a ser inserido: ");
							scanf("%d", &num);
							inserePilha(num, &topo);
						} break;

						case 5: {
							imprimePilha(topo);
						} break;

						case 6: {
							if(topo == NULL) printf("\nLista vazia!");
							else removePilha(&topo);
						} break;

						case 7: {
							if(inicio) {
								inserePilha(inicio->chave, &topo);
								removeFila(&inicio);
								if(!inicio) fim = inicio;
							}
							else printf("Fila vazia\n");
						} break;

						case 8: {
							if(topo) {
								insereFila(&fim, topo->chave);
								if(!inicio) inicio = fim;
								removePilha(&topo);
							}
							else printf("Pilha vazia\n");
						} break;

						case 0: 
						case 9: {
							while(inicio != NULL) removeFila(&inicio);
							if(inicio==NULL) fim = inicio; //fim=NULL;
							while(topo != NULL) removePilha(&topo);
						} break;

						default: {
							printf("Opcao invalida\n");
						} break;
					}
				} while(op2 != 0);
			} break;

			case 0: break;
		
			default: {
				printf("Opcao invalida\n");
			} break;
		}
	} while(op1 != 0);
}
