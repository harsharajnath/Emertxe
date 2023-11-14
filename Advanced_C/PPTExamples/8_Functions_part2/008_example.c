#include<stdio.h>
int add(int num1, int num2)
{
    return num1 + num2;
}
int sub(int num1, int num2)
{
    return num1 - num2;
}
int oper(int (*f)(int, int), int a, int b)
{
    return f(a, b);
}
int main()
{
    int (*f[])(int, int) = {add,sub};

    printf("%d\n", oper(f[0], 2, 4));
    printf("%d\n", oper(f[1], 2, 4));

    return 0;
}

