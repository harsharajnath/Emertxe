#include<stdio.h>

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};

    int size;

    size = sizeof (arr) / sizeof(arr[0]);

    printf("%d\n", size);

    return 0;
}