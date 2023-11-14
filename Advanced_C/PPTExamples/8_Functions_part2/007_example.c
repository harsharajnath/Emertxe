#include<stdio.h>
int add(int num1, int num2)
{
    return num1 + num2;
}
int sub(int num1, int num2)
{
    return num1 - num2;
}
int main()
{
    int (*f[])(int, int) = {add,sub};

    printf("%d\n", f[0](2, 4));
    printf("%d\n", f[1](2, 4));

    return 0;
}

