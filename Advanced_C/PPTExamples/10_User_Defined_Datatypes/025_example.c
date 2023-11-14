#include<stdio.h>
typedef int array_of_100[100];

int main()
{
    array_of_100 array;
    printf("%zu\n", sizeof(array));

    return 0;
}
