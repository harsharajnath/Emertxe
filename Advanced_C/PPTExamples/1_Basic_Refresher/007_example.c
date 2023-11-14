#include <stdio.h>
int main()
{
    unsigned int count1 = 10;
    signed int count2 = -1;

    if ( count1 > count2 )
    {
	printf("Yes\n");
    }
    else
    {
	printf("No\n");
    }

    return 0;
}

