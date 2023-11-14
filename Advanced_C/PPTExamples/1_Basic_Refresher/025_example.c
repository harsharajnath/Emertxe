#include <stdio.h>
int main()
{
    int x = 7, y = 7;
    x = 7 << 32;
    printf("x is %x\n", x);
    x = y << 32;
    printf("x is %x\n", x);
    return 0;
}
