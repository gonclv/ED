#include <stdio.h>
#include <stdlib.h>

void main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int *vet1 = (int *) malloc(sizeof(int) * m);
    int *vet2 = (int *) malloc(sizeof(int) * n);

    for(int i = 0; i < m; i++) {
        scanf("%d", &vet1[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &vet2[i]);
    }



}