#include <stdio.h>
int main()
{
    int i = 10;
    int i = 20;
    {
	printf("i %d\n", i);
    }
    printf("i %d\n", i);
    return 0;
}
