#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *ptr;
    ptr = malloc(6);
    strcpy(ptr,"Hello");
    puts(ptr);
    return 0;
}
