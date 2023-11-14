#include <stdio.h>
int main()
{
    if (sizeof(char *) == sizeof(long long *))
    {
	printf("Yes its Equal\n");
    }
    return 0;
}
