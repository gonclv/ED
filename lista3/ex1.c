#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
} pessoa;

int iguais(pessoa pessoa1, pessoa pessoa2) {
    if((pessoa1.idade == pessoa2.idade) && !strcmp(pessoa1.nome, pessoa2.nome))
        return 1;
    else
        return 0;
}

void main() {
    pessoa pessoa1, pessoa2;
    fgets(pessoa1.nome, 64, stdin);
    scanf("%d", &pessoa1.idade);
    setbuf(stdin, NULL);
    fgets(pessoa2.nome, 64, stdin);
    scanf("%d", &pessoa2.idade);

    if(iguais(pessoa1, pessoa2))
        printf("Mesma pessoa\n");
    else
        printf("Pessoas diferentes\n");
}