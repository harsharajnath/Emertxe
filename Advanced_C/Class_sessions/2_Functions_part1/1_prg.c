#include<stdio.h>

int evenodd(int);

int main()
{
    int num, res;

    printf("Enter the number: \n");

    scanf("%d", &num);

    res = evenodd(num);

    res == 0? printf("Neither odd or even\n"): (res == 1 ? printf("Even\n"): printf("odd\n"));

    return 0;

}

int evenodd(int n)
{
    return (n == 0? 0 : (n % 2 == 0? 1: -1));

}