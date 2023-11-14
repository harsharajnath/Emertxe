#include <stdio.h>
int main()
{
    int num = 100, ret;
    printf("The enter a number [is 100 now]: ");
    ret = scanf("%d", &num);
    if (ret != 1)
    {
	printf("Invalid input. The number is still %d\n", num);
	return 1;
    }
    else
    {
	printf("Number is modified with %d\n", num);
    }
    return 0;
}
