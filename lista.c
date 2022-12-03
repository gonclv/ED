#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct no {
  int chave;
  struct no *prox;
} TNo;

TNo *alocaNo(int k);
void insereNo(TNo **p, int k);
void imprimeLista(TNo *p);
TNo *buscaNo(TNo *p, int k);

int main() {
    TNo *prim=NULL, *achou=NULL;

    insereNo(&prim, 22);
    insereNo(&prim, 80);
    insereNo(&prim, 36);
    insereNo(&prim, 77);

    //printf("\n%d", prim->chave);
    imprimeLista(prim);

    achou = buscaNo(prim, 80);
    if(achou) {
        printf("\n%p %d", achou, achou->chave);
    }
    else {
        printf("\nNo nao achou");
    }
}
 
TNo *alocaNo(int k)
{
    TNo *novo=NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if(novo) { //if(novo!=NULL)
        novo->chave = k;
        novo->prox = NULL;
    }
    else {
        printf("\nMemoria nao alocada");
        return NULL;
    }
    return(novo);
}

void insereNo(TNo **p, int k)
{
    assert(p);
    TNo *novo;
    novo = alocaNo(k);
    if(novo) //if(novo!=NULL)
    {
        novo->prox = *p; //*p == prim
        *p = novo;
    }
    else
    {
        printf("\nNao houve alocacao!");
    }
}
void imprimeLista(TNo *p)
{
    //assert(p);
    if(p) //p!=NULL
    {
        while(p!=NULL)
        {
        printf("\n%d", p->chave);
        p = p->prox;
        }
    }
    else
        printf("\nLista vazia");
}
TNo *buscaNo(TNo *p, int k)
{
    //assert(p);
    if(p) //p!=NULL
    {
        while(p!=NULL)
        {
        //printf("\n%d", p->chave);
        if(p->chave == k)
            return p;
        p = p->prox;
        }
        return NULL;
    }
    else
        printf("\nLista vazia");
}