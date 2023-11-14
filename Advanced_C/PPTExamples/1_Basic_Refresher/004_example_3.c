#include <stdio.h>

int main()
{
    short int count1;
    long int count2;
    short count3;

    printf("short is %u bytes\n", sizeof(count1));
    printf("long is %u bytes\n", sizeof(count2));
    printf("short is %u bytes\n", sizeof(count3));

    return 0;
}
