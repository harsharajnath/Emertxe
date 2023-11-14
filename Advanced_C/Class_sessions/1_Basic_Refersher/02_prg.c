#include<stdio.h>

int main()

{

    int x = 10;

    printf("%d\n", x); //10
    printf("%d\n", ++x); //11
    printf("%d\n", x++); //11
    printf("%d\n", x); //12

    return 0;
}