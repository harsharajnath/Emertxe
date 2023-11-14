#include <stdio.h>
int foo()
{
    static int i;
    return i;
}
int main()
{
    static int x = foo ();
    printf("x %d\n", x);
    return 0;
}
