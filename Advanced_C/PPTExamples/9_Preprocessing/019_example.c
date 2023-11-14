#include <stdio.h>
#define METHOD1
int main()
{
#if defined (METHOD1)
    puts("Hello World");
#endif
#if defined (METHOD2)
    printf("Hello World");
#endif
#if defined (METHOD1) && defined (METHOD2)
    puts("Hello World");
    printf("Hello World");
#endif
    return 0;
}
