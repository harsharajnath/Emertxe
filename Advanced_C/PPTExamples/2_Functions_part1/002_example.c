#include <stdio.h>
int add_numbers(int, int);
int main()
{
    int num1 = 10, num2 = 20;
    int sum = 0;
    sum = add_numbers(num1, num2);
    printf("Sum is %d\n", sum);
    return 0;
}
int add_numbers(int num1, int num2)
{
    int sum = 0;
    sum = num1 + num2;
    return sum;
}
