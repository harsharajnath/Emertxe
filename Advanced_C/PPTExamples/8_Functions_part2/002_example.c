#include <stdio.h>
int add(int num1, int num2)
{
    return num1 + num2;
}
int main()
{
    printf("%p\n", add);
    printf("%p\n", &add);
    return 0;
}
