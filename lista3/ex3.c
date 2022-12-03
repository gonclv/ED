#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
} pessoa;

int buscaLinear(const char nome[64], pessoa vet[], int tam) {
    int comparar;

    for(int i = 0; i < tam; i++) {
        comparar = strcmp(nome, vet[i].nome);

        if(!comparar)
            return i;
    }

    return -1;
}

void main() {
    pessoa graduadosDeHogwarts[4] = {
        {"Harry", 35},
        {"Hermione", 36},
        {"Ronald", 35},
        {"Ginevra", 34}
    };

    pessoa a = {"Hermione", 35};

    fgets(a.nome, 64, stdin);
    scanf("%d", &a.idade);

    FILE *arq = NULL;
    arq = fopen("hogwarts.txt", "w");
    
    if(arq) {
        fprintf(arq, "%s %d", a.nome, a.idade);
        fclose(arq);
        arq = NULL;
    }
    else {
        printf("Erro\n");
    }

    arq = fopen("hogwarts.txt", "r");
    if(arq){
        while(!feof(arq)) {
            fscanf(arq, "%s %d", &a.nome, &a.idade);
            printf("%s %d\n", a.nome, a.idade);
        }
    }
    else {
        printf("Erro\n");
    }

    int buscar = buscaLinear(a.nome, graduadosDeHogwarts, 4);

    if(buscar < 0)
        printf("Pessoa não encontrada.\n");
    else
        printf("Pessoa encontrada na posição %d\n", buscar);
}