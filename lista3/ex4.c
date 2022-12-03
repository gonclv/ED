#include <stdio.h>

typedef struct {
    int vet[100];
    int n;
} lista;

void adicionar(lista *pa) {
    for(int i = 0; i < 5; i++) {
    if(pa->n < 100) {
        int x;
        scanf("%d", &x);
        pa->vet[pa->n] = x;
        pa->n++;
    }
    else {
        printf("A lista está cheia.\n");
    }
    }
}

int nElementos(lista *pa) {
    return pa->n;
}

void imprimir(lista *pa) {
    for(int i = 0; i < pa->n; i++) {
        printf("%d\n", pa->vet[i]);
    }
}

int remover(lista *pa) {
    int x;
    scanf("%d", &x);
    for(int i = 0; i < pa->n; i++) {
        if(pa->vet[i] == x) {
            pa->vet[i] = 0;
            (pa->n)--;
            return -1;
        }
    }
    printf("Elemento não está na lista.\n");
    return 0;
}

void main() {
    lista a;
    a.n = 0;
    int contar = 0, teste;

    adicionar(&a);
    contar = nElementos(&a);
    printf("%d\n", contar);
    teste = remover(&a);
    if(teste) {
        printf("Elemento removido com sucesso\n");
    }
    imprimir(&a);
    contar = nElementos(&a);
    printf("%d\n", contar);
}