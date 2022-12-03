#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
} pessoa;

int iguaisRef(char *nome1, int *idade1, char *nome2, int *idade2) {
    if((*idade1 == *idade2) && !strcmp(nome1,nome2))
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

    if(iguaisRef(&(a.nome), &(a.idade), &(b.nome), &(b.idade)))
        printf("Mesma pessoa\n");
    else
        printf("Pessoas diferentes\n");
}