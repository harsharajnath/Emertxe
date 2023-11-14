#include<stdio.h>
#include<string.h>

int my_strlen(char *str)
{
    int count = 0;
    while(*str++)
    {
	count++;
    }
    return count;
}

int main()
{
    char str[] = "Hello World";
    int ret;

    ret = my_strlen(str);
    printf("%d is the string length of %s\n", ret, str);

    return 0;
}
