#include <stdio.h>
#define tam 4 //qtd de alunos

float variancia(int faltas[], float media);

void main() {
    int faltas[tam], soma, i = 0;
    float media = 0, res;

    for (i = 0; i < tam; i++) {
        printf("Número de faltas do aluno %d:\n", i);
        scanf("%d", &faltas[i]);
        soma = soma + faltas[i];
    } //qdo terminar terei o valor preenchido com faltas e soma das faltas

    media = (float)soma / tam;
    res = variancia(faltas, media);
    printf("Variância = %f\n", res);
}

float variancia(int faltas[], float media) {
    int i;
    float somatorio = 0, resultado;
    for (i = 0; i < tam; i++) {
        somatorio = somatorio + (faltas[i] - media) * (faltas[i] - media);
    }
    resultado = ((float)1 / tam) * somatorio;
    return resultado;
}