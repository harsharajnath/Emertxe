#include <stdio.h>
#define SET_BIT(num, pos)	(num | (1 << pos))
int main()
{
    printf("%d\n", 2 * SET_BIT(0, 2));
    return 0;
}
