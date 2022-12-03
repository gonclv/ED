#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct no {
    int chave;
    struct no *prox;
} TNo;

typedef struct no {
    int chave;
    TNo *inicio;
    TNo *fim;
} TNoCab;

TNoCab *criaLista();
TNo *alocaNo(int k);
void insereLista3(TNoCab *lista, int k);

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

TNoCab *criaLista() {
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

void insereLista3(TNoCab *lista, int k) {
    TNo *novo = alocaNo(k);

    if (novo == NULL) {
        return;
    }

    novo->prox = lista->prox;
    lista->prox = novo;
}