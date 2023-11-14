#include <stdio.h>

int main()

{
    printf("%c\n", 'A');
    printf("%d %i\n", 10, 10);
    printf("%o\n", 8);
    printf("%x %X %x\n", 0xA, 0xA, 10);
    printf("%u\n", 255);
    printf("%f %F\n", 2.0, 2.0);
    printf("%e %E\n", 1.2, 1.2);
    printf("%a%A\n", 123.4, 123.4);
    printf("%g %G\n", 1.21, 1.0);
    printf("%s\n", "Hello");

    return 0;

}
