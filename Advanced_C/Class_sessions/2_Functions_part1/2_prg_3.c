#include<stdio.h>

void fun(int a)

{
    printf("%d\n", a);
}
int main()
{
    static int a = 10;
    a++;
    fun(a);
    a++;
    fun(a);
    a++;
    fun(a);

    return 0;
}