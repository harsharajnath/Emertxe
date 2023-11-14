#include <stdio.h>

int main()
{
    short int count1 = 5;
    long double count2 = 2.5;
    short count3;

    printf("short is %u bytes\n", sizeof(5));
    printf("long is %u bytes\n", sizeof(2.5));
    printf("short is %u bytes\n", sizeof(short));
    printf("10 is taken as integer, i.e %u bytes\n", sizeof(10));

    return 0;
}
