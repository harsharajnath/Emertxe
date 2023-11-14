#include <stdio.h>
int main()
{
    extern char x;
    printf("x %c\n", x);
    return 0;
}
int x = 0x31;
