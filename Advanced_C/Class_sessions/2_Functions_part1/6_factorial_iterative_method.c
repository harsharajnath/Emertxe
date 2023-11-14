#include<stdio.h>

int factorial (int num)

{

    int fact = 1, i;

    for(i = 1; i <= num; i++)

    {

        fact = fact * i;

    }
    return fact;

}
int main()
{
    int num = 3;

    int fact;

    fact = factorial(3);

    printf("The factorial of %d is %d\n", num, fact);

    return 0;
}