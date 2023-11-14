#include <stdio.h>
#include <stdlib.h>
int main()
{
    int (*a)[3] ;
    a = malloc(2 * sizeof(int [3]));
    return 0;
}
