#include <stdio.h>
#define METHOD
int main()
{
#if METHOD == 1
    puts("Hello World");
#endif
#if METHOD == 2
    printf("Hello World");
#endif
    return 0;
}
