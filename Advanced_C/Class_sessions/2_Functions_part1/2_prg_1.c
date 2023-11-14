#include<stdio.h>

void fun()

{

    int a = 10;
    a++;
    printf("%d\n", a);
}
int main()
{
    fun();

    fun();

    fun();

    return 0;
}