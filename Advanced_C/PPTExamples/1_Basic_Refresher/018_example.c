#include <stdio.h>
int main()
{
    int num1 = 5;
    int num2 = sizeof(++num1);
    printf("num1 is %d and num2 is %d\n", num1, num2);
    return 0;
}
