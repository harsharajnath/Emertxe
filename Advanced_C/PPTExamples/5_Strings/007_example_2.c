#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Hello";
    int ret;
    ret = strlen(str);
    printf("%d\n", ret);

    ret = sizeof(str);
    printf("%d\n", ret);

    return 0;
}
