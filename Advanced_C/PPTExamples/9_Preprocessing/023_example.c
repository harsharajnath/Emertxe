#include <stdio.h>
int main()
{
    int x = 10, y = 20;
#ifdef SPACE_OPTIMIZED
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("Selected Space Optimization\n");
#else
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("Selected Time Optimization\n");
#endif
    return 0;
}
