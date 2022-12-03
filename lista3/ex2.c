#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
} pessoa;

int iguaisRef(pessoa *a, pessoa *b) {
    if((a->idade == b->idade) && !strcmp(a->nome, b->nome))
        return 1;
    else
        return 0;
}

void main() {
    pessoa a, b;
    fgets(a.nome, 64, stdin);
    scanf("%d", &a.idade);
    setbuf(stdin, NULL);
    fgets(b.nome, 64, stdin);
    scanf("%d", &b.idade);

    if(iguaisRef(&a, &b))
        printf("Mesma pessoa\n");
    else
        printf("Pessoas diferentes\n");
}