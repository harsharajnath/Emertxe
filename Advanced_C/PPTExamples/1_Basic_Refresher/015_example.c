#include <stdio.h>
int main()
{
    int iter;
    for (iter = 0; iter < 10; iter++)
    {
	if (iter == 5)
	{
	    continue ;
	}
	printf("%d\n", iter);
    }
    return 0;
}
