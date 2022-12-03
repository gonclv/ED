#include <stdio.h>
#include <stdlib.h>

void soma(int *n) {
    *n = ++(*n);
}

void main() {
    /*
    int x = 5;
    printf("%d\n", x);
    soma(&x);
    printf("%d\n", x);
    
    int vet[5]={1,2,3,4,5};
    int *p = malloc(sizeof(int) * 5);

    for (int i = 0; i < 5; i++) {
        *(p+i) = i;
        printf("%p = %p\n", vet+i, &vet[i]);
        printf("%d\n", *(p+i));
    }
    */

    int *pvet[2];
    int x = 10, y[2] = {20,30};
    pvet[0] = &x;
    pvet[1] = y;

    printf("%p = %d\n", pvet[0], **(pvet + 0));
    printf("%p = %d\n", pvet[1], **(pvet + 1));
    printf("%p = %d\n", *(pvet + 1) + 1, *(*(pvet + 1) + 1));
}