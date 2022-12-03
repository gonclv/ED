#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct no {
    int chave;
    struct no *prox;
} TNo;

TNo *criaLista();
TNo *alocaNo(int k);
void insereLista2(TNo *lista, int k);
void imprimeLista(TNo *p);
void desalocaNo2(TNo *lista);

void main() {
    TNo *cabeca = criaLista();
    insereLista2(cabeca, 7);
    insereLista2(cabeca, 12);
    insereLista2(cabeca, 78);
    insereLista2(cabeca, 1);
    imprimeLista(cabeca->prox);
    while(cabeca->prox != NULL) {
        desalocaNo2(cabeca);
    }
    imprimeLista(cabeca->prox);
}

TNo *criaLista() {
    TNo *cabeca = NULL;
    //cabeca = alocaNo(-1);
    cabeca = (TNo *)malloc(sizeof(TNo));

    if (cabeca == NULL) {
        return NULL;
    }

    cabeca->chave = -1;
    cabeca->prox = NULL;
    return cabeca; 
}

TNo *alocaNo(int k)
{
    TNo *novo = NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if(novo) //if(novo!=NULL)
    {
        novo->chave = k;
        novo->prox = NULL;
    }
    else
    {
        printf("\nMemória não alocada");
        return NULL;
    }
    return novo;
}

void insereLista2(TNo *lista, int k) {
    TNo *novo = alocaNo(k);

    if (novo == NULL) {
        return;
    }

    novo->prox = lista->prox;
    lista->prox = novo;
}

void imprimeLista(TNo *p)
{
    //assert(p);
    if(p) //p!=NULL
    {
        while(p!=NULL)
        {
        printf("%d\n", p->chave);
        p = p->prox;
        }
    }
    else
        printf("Lista vazia\n");
}

void desalocaNo2(TNo *lista) {
    TNo *aux = lista->prox;
    if(aux == NULL) {
        printf("Lista vazia\n");
        return;
    }
    lista->prox = aux->prox;
    free(aux);
    aux = NULL;
}