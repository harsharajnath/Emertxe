#include <stdio.h>
int main()
{
    int x;
    {
	int x = 10;
	{
	    extern int x = 20;
	    printf("x %d\n", x);
	}
	printf("x %d\n", x);
    }
    printf("x %d\n", x);
    return 0;
}
int x;
