#include <stdio.h>

int add(int, int);
int mul(int, int);
int sub(int, int);

int main()
{
    int num1, num2;

    printf("Enter the 2 values\n");
    scanf("%d %d", &num1, &num2);

    printf("Addition of values is : %d\n", add(num1, num2));
    printf("Multiplication of values is : %d\n", mul(num1, num2));
    printf("Addition of values is : %d\n", sub(num1, num2));

    return 0;
}
