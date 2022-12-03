#include <stdio.h>

void main() {
    /*
    int x = 10, *y = NULL, z = -1;
    float r;
    
    y = &x;
    printf("%p\n", &x);
    printf("%p\n", y);
    printf("%p\n", &y);
    printf("%d\n", *y);

    y = &z;
    x = 30;
    printf("%d\n", *y);

    y = &r;

    if (y)
        printf("Com endereço\n");
    else
        printf("Sem endereço\n");
    

    int x = 10;
    int *p;

    p = &x;
    printf("x = %d\n", x);
    *p = 12;
    printf("x = %d\n", x);
    printf("p = %d\n", *p);
    

   int x = 10, z = 30, *y = NULL, res;
   y = &res;
   *y = x + z;
   
   printf("res = %d\n", res);
   y += 3;
   printf("%p = %d\n", y, *y);
   */

  void *pp;
  int p2 = 10;

  pp = &p2;
  printf("p2 = %d\n", *(int*)pp);
}