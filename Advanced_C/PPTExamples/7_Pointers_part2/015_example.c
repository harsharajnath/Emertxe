#include <stdio.h>
void print_array(int p[2][3])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
	for (j = 0; j < 3; j++)
	{
	    printf("%d ", p[i][j]);
	}
	printf("\n");
    }
}
int main()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    print_array(a);
    return 0;
}
