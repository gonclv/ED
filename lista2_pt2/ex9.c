#include <stdio.h>

char str2[100];

char *strcopy(char *str) {
    for (int i = 0; *(str +i) != '\0'; i++) {
        *(str2 + i) = *(str + i);
    }

    return str2;
}

void main() {
    char str[100];
    setbuf(stdin, NULL);
    fgets(str, 100, stdin);
    char *str2 = strcopy(str);
    printf("%s", str2);
}