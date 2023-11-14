#include <stdio.h>
int main()
{
    int count;
    unsigned char iter = 0xFF;
    for (count = 0; iter != 0; iter >>= 1)
    {
	if (iter & 01)
	{
	    count++;
	}
    }
    printf("count is %d\n", count);
    return 0;
}
