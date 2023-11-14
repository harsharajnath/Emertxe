#include <stdio.h>
int main()
{
    int j = 10;
    {
	int j = 0;
	printf("j %d\n", j);
    }
    printf("j %d\n", j);
    return 0;
}
