#include <stdio.h>

typedef struct teste {
    int x;
} TTeste;


int function(int i) {
    TTeste *p = NULL;
    p->x = i;
    //printf("%d\n", i);
    return function(i+1);
}

void main() {
    printf("\n\n\n");
    printf("\n\n\n%d\n\n\n", function(1));
}