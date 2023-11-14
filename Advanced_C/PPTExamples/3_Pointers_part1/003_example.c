#include <stdio.h>
int main()
{
    int number = 10;
    int *ptr;
    ptr = &number;
    printf("Address of number is %p\n", &number);
    printf("ptr contains %p\n", ptr);
    return 0;
}
