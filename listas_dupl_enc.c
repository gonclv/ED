#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct no {
    int chave;
    struct no *ant;
    struct no *prox;
} TNo;

TNo *insereLista(TNo *p, int chave) {
    //assert(p);
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    novo->chave = chave;
    novo->prox = p;
    novo->ant = NULL;

    if(p!=NULL) {
        p->ant = novo;
    }

    return novo;
}

void insereLista2(TNo **p, int chave) {
    //assert(p);
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    novo->chave = chave;
    novo->prox = *p;
    novo->ant = NULL;

    if(*p!=NULL) {
        (*p)->ant = novo;
    }

    *p = novo;
}

TNo *buscaLista(TNo *p, int elem){
    TNo *paux;

    for(paux = p; paux != NULL; paux = paux->prox) {
        if(paux->chave == elem) {
            return paux;
        }
    }

    return NULL;
}


void imprimeLista(TNo *p) {
    TNo *paux;
    if(p==NULL) {
        printf("Lista vazia\n");
        return;
    }

    for(paux = p; paux != NULL; paux = paux->prox) {
        printf("%d\n", paux->chave);
    }
}

void imprimeListaInv(TNo *p) {
    TNo *paux;
    if(p==NULL) {
        return;
    }

    for(paux = p; paux != NULL; paux = paux->prox) {
        printf("%d\n", paux->chave);
    }
}

void desaloca(TNo **p) {
    TNo *aux = *p;
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
    TNo *prim = NULL,  *prim2 = NULL, *achou;
    prim = insereLista(prim, 0);
    insereLista2(&prim, 10);
    insereLista2(&prim, 20);
    insereLista2(&prim, 30);
    insereLista2(&prim, 40);
    insereLista2(&prim2, 50);
    insereLista2(&prim2, 60);

    achou = buscaLista(prim, 10);

    if(achou) {
        printf("%d encontado\n", achou->chave);
    }
    else {
        printf("Elemento não encontrado\n");
    }

    imprimeLista(prim);
    desaloca(&prim);
    printf("\n");
    imprimeListaInv(prim);

    while(prim!=NULL) {
        desaloca(&prim);
    }

    printf("\n");
    imprimeLista(prim);
}
