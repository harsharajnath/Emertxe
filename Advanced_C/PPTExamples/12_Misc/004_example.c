#include <stdio.h>
int main()
{
    int num1;
    volatile int num2 = 1;
    num1 = ++num2 + num2++ + num2++ + num2++;
    printf("%d\n", num1); 
    return 0;
}
