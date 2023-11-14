#include <stdio.h>
int main()
{
    char string[10];
    scanf("%[a-z A-Z 0-9]", string);
    printf("%s\n", string);
    return 0;
}
