#include <stdio.h>

int main()
{
    printf("%#x %#X %#x\n", 0xA, 0xA, 10);
    printf("%#o\n", 8);

    printf("%-3d %-3d\n", 1, 1);
    printf("%-3d %-3d\n", 10, 10);
    printf("%-3d %-3d\n", 100, 100);

    printf("% 3d\n", 100);
    printf("% 3d\n", -100);

    return 0;
}