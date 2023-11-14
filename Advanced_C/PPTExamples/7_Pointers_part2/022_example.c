#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **a ;
    int i;
    a = malloc(2 * sizeof(int *));
    for (i = 0; i < 2; i++)
    {
	a[i] = malloc(3 * sizeof(int));
    }
    return 0;
}
