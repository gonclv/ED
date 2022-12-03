#include <stdio.h>

typedef struct aluno {
	int ra;
	char nome[15];
	float rendaFamiliar;
} TAluno;

int main() {
	FILE *arq = NULL;
	TAluno a1;
	int qtde, i;
	printf("Informe qtde de alunos\n");
	scanf("%d", &qtde);

	arq = fopen("alunos.txt", "a");

	if(!arq) {
		printf("Erro na abertura do arquivo.\n");
	}
	else {
		for(i = 0; i < qtde; i++) {
			printf("Informe ra: ");
			scanf("%d", &a1.ra);
			printf("Informe nome: ");
			setbuf(stdin, NULL);
			fgets(a1.nome, 50, stdin);
			printf("Informe renda familiar: ");
			setbuf(stdin, NULL);
			scanf("%f", &a1.rendaFamiliar);

			fprintf(arq, "%d ", a1.ra);
			fprintf(arq, "%s ", a1.nome);
			fprintf(arq, "%f\n", a1.rendaFamiliar);
		}

		fclose(arq);
		arq = fopen("alunos.txt", "r");
		if(!arq)
			printf("Erro na abertura do arquivo\n");
		else {
			while(!feof(arq)) {
				fscanf(arq, "%d %s %f", &a1.ra, &a1.nome, &a1.rendaFamiliar);
				if(feof(arq))
					break;
				printf("%d %s %f\n", a1.ra, a1.nome, a1.rendaFamiliar);
			}
		}
	}

	return 0;
}