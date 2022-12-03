#include <stdio.h>
#include <string.h> //manipulacao de strings: strcpy, strcat, strcmp, strlen

void main() {
    char nome[10] = {'d', 'a', 'n', 'i', 'l', 'o', '\0'};
    char nome2[10];
    char nome3[10] = "Simone";
    char nome4[10];
    char nome5[10];
    char nome6[11];

    scanf("%s", nome4);
    //para string não precisa do &, mas pode colocar
    setbuf(stdin, NULL);

    scanf("%[^\n]", &nome5);
    setbuf(stdin, NULL);

    fgets(nome6, 11, stdin);
    //fç seguranca - armazena somente tam da string

    /* for (int i = 0; i < 10; i++)
        nome2[i] = nome[i];
        //função na biblioteca string.h: strcpy
    */
    strcpy(nome2, nome);
    
    printf("%s\n", nome);
    printf("%s\n", nome2);
    printf("%s\n", nome3);
    printf("%s\n", nome4);
    printf("%s\n", nome5);
    printf("%s\n", nome6);
}