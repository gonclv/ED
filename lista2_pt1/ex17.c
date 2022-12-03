#include <stdio.h>

void calcula_media(float *matriz, float *vetor, int l, int c) {
    float soma = 0;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            soma = soma + *matriz;
            matriz++;
        }
        *vetor = soma / c;
        vetor++;
        soma = 0;
    }
}

void main() {
    int l, c;
    printf("Digite o número de alunos: ");
    scanf("%d", &l);
    printf("Digite o número de notas: ");
    scanf("%d", &c);
    float notas[l][c];
    float medias[l];

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("Digite a nota %d do aluno %d: ", j + 1, i + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    calcula_media(notas, medias, l, c);

    for(int i = 0; i < l; i++) {
        printf("Média do aluno %d: %.2f\n", i + 1, *(medias + i));
    }
}