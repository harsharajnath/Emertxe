#include <stdio.h>
int main()
{
    int num = 10;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    printf( "%p\n", ptr3);
    printf( "%p\n", *ptr3);
    printf( "%p\n", **ptr3);
    printf( "%d\n", ***ptr3);
    return 0;
}
