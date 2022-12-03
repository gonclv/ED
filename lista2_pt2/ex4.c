#include <stdio.h>

int fat(int x) {
    if (x == 0) {
        return 1;
    } else {
        return x * fat(x - 1);
    }
}

void troca(int *a, int *b) {
    *a = *a * *a;
    *b = fat(*b);
}

void main() {
    int a, b;
    scanf("%d %d", &a, &b);

    troca(&a, &b);

    printf("A elevado ao quadrado = %d\n", a);
    printf("Fatorial de B = %d\n", b);
}