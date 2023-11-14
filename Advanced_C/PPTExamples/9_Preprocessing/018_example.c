#include <stdio.h>
#undef METHOD1
int main()
{
#ifndef METHOD1
    puts("Hello World");
#else
    printf("Hello World");
#endif
    return 0;
}
