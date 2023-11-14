#include<stdio.h>
#include<string.h>
int main()
{
    char str[] = "Hello World";
    int ret;
    ret = strlen(str);
    printf("%d is the string length of %s\n", ret, str);
    return 0;
}
