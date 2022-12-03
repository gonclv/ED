#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
} pessoa;

int iguais(char *nome1, int idade1, char *nome2, int idade2) {
    if((idade1 == idade2) && !strcmp(nome1, nome2))
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

    if(iguais(pessoa1.nome, pessoa1.idade, pessoa2.nome, pessoa2.idade))
        printf("Mesma pessoa\n");
    else
        printf("Pessoas diferentes\n");
}