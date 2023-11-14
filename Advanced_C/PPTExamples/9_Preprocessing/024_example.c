#include <stdio.h>
#if defined DEBUG_PRINT
#warning "Debug print enabled"
#endif
int main()
{
    int sum, num1, num2;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);
#ifdef DEBUG_PRINT
    printf("The entered values are %d %d\n", num1, num2);
#endif
    sum = num1 + num2;
    printf("The sum is %d\n", sum);
    return 0;
}
