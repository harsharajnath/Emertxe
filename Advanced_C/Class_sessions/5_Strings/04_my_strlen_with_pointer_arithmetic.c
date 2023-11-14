#include<stdio.h>
#include<string.h>
int my_strlen(char *str)
{
    char *ptr = str;
    while ( *str++);
    return str - ptr - 1;
}
int main()
{
    char str[] = "Hello World";
    int ret;
    ret = my_strlen(str);
    printf("%d is the string length of %s\n", ret, str);
    return 0;
}

