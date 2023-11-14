#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *ptr;
    ptr = malloc(600000000000000000000);

    if(ptr == NULL)
    {
	printf("failed to allocate memory\n");
	return 1;
    }
    strcpy(ptr,"Hello");
    puts(ptr);
    return 0;
}
