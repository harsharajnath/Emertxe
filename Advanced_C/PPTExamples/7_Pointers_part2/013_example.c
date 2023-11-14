#include<stdio.h>
#include<stdlib.h>
int main()
{
    int (*p)[3];
    p = malloc(sizeof(*p) * 3);
    (*(p + 0))[0] = 1;
    (*(p + 1))[1] = 2;
    (*(p + 2))[2] = 3;
    printf("%d\n", p[0][0]);
    printf("%d\n", p[1][1]);
    printf("%d\n", p[2][2]);
    return 0;
}
