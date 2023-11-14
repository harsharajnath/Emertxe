#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    int *ptr;

    int num = 1;

    printf("num --> %d\n", num);
    printf("ptr --> %p\n\n", ptr);

    num++;

    ptr++;

    printf("num --> %d\n", num);

    printf("ptr --> %p\n", ptr);

    return 0;

}