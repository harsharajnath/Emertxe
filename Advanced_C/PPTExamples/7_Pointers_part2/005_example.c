#include <stdio.h>
int main()
{
    int a[2] = {10, 20};
    int b[2] = {30, 40};
    int c[2] = {50, 60};
    int *ptr[3];
    ptr[0] = a;
    ptr[1] = b;
    ptr[2] = c;
    return 0;
}
