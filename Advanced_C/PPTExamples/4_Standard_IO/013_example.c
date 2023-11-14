#include <stdio.h>
int main()
{
    int ret;
    char string[] = "Hello World";
    ret = printf("%s\n", string);
    printf("The previous printf() printed %d chars\n", ret);
    return 0;
}
