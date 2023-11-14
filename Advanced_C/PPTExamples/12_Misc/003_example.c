#include <stdio.h>
int main()
{
    int get_out;
    volatile int num = 0;
    scanf("%d", &get_out);
    while (get_out)
    {
	num++;
    }
    return 0;
}
