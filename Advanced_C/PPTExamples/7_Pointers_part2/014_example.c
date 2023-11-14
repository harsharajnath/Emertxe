#include<stdio.h>
int main()
{
    int (*p)[3];
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    p = a;
    return 0;
}
