#include <stdio.h>
int main()
{
    if (sizeof("Hello" "World") == sizeof("Hello") + sizeof("World"))
    {
	printf("WoW\n");
    }
    else
    {
	printf("HuH\n");
    }
    return 0;
}
