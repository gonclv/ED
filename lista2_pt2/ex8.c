#include <stdio.h>

void mm(int *pvet, int n, int *min, int *max) {
    *min = *max = *pvet;

    for(int i = 0; i < n; i++) {
        if (*(pvet + i) < *min) {
            *min = *(pvet + i);
        }

        if (*(pvet + i) > *max) {
            *max = *(pvet + i);
        }
    }
}

void main() {
    int n, min, max;

    scanf("%d", &n);
    int vet[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    mm(vet, n, &min, &max);

    printf("%d\n", min);
    printf("%d\n", max);
}