#include <stdio.h>
int add(int num1, int num2)
{
    return num1 + num2;
}
int main()
{
    int (*fptr)(int, int);
    fptr = add;
    printf("%d\n", fptr(2, 4));
    printf("%d\n", (*fptr)(2, 4));
    return 0;
}
