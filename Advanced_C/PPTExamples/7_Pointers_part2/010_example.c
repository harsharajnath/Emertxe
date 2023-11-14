#include<stdio.h>
int main()
{
    int array[3] = {1, 2, 3};
    int (*ptr)[3];
    ptr = array;
    printf("%d\n", **ptr);
    return 0;
}
