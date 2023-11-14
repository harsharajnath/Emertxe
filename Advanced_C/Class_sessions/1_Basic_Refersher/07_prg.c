#include <stdio.h>

int main()

{

    int i, j;

    for(i = 0, j = 0; i < 5, j < 10; i++, j++)
    {
        printf("Hello\n");

    }
    printf("Looped i = %d, j = %d\n", i,j);

    return 0;

}