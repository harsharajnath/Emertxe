#include<stdio.h>

int main()
{
    int num= 12, i;

    for(i = 0; i < 32; i++)
    {

        if (num & (1 << (31 - i)))
            printf("1");

        else

            printf("0");

    }
    printf("\n");
    return 0;
}