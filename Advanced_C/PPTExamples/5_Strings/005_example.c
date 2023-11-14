#include <stdio.h>
int main()
{
    char str1[6] = "Hello";
    char str2[6];
    //str2 = "World";
    char *str3 = "Hello";
    char *str4;
    str4 = "World";
    str1[0] = 'h';
    //str3[0] = 'w';
    printf("%s\n", str1);
    printf("%s\n", str2);
    return 0;
}
