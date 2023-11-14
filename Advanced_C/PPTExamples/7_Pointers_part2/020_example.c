#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a[2] ;
    for (int i = 0; i < 2; i++)
    {
	a[i] = malloc(3 * sizeof(int));
    }
    return 0;
}
