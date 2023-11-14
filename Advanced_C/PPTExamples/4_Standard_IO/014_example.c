#include <stdio.h>
int main()
{
    int num1 = 123;
    char ch = 'A';
    float num2 = 12.345;
    char string1[] = "sprintf() Test";
    char string2[100];
    sprintf(string2, "%d %c %f %s\n", num1, ch, num2, string1);
    printf("%s", string2);
    return 0;
}
