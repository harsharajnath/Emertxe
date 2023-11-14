#include<stdio.h>

int *fun()

{

    int a = 10;
    return &a;

}

int main()

{

    int *ptr;
    ptr = fun();
    printf("%d\n", *ptr);

    return 0;


}