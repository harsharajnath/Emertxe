#include <stdio.h>
int main()
{
    int num1 = 1, num2 = 1;
    float num3 = 1.7, num4 = 1.5;
    num1 += num2 += num3 += num4;
    printf("num1 is %d\n", num1);
    return 0;
}
