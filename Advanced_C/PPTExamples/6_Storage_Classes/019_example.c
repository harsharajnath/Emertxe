#include <stdio.h>
int *foo()
{
    int i = 10;
    static int *j = &i;
    return j;
}
int main()
{
    int *i;
    i = foo();
    printf("*i %d\n", *i);
    return 0;
}
