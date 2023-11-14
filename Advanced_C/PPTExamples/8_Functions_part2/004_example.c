#include <stdio.h>
int add(int num1, int num2)
{
    return num1 + num2;
}
int main()
{
    int (*fptr)(int, int);
    fptr = add;
    printf("%p\n", add);
    printf("%p\n", fptr);
    printf("%p\n", &fptr);
    return 0;
}
