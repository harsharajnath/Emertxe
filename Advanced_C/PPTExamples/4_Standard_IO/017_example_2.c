#include <stdio.h>
int main()
{
    int num1;
    char ch;
    float num2;
    char string[20];
    scanf("%19[^\n]", string);
    printf("%s\n", string);
    return 0;
}
