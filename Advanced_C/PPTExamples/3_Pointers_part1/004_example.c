#include <stdio.h>
int main()
{
    int number = 10;
    int *ptr;
    ptr = &number;
    printf("number contains %d\n", number);
    printf("*ptr contains %d\n", *ptr);
    return 0;
}
