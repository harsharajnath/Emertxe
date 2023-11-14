#include <stdio.h>
register int x;
int foo()
{
    printf("x %d\n", x);
    return ++x;
}
int main()
{
    foo();
    printf("x %d\n", x);
    return 0;
}
