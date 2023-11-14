#include <stdio.h>
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    printf("%p\n", a + 1);
    printf("%p\n", &a[0] + 1);
    printf("%p\n", &a + 1);
    return 0;
}
