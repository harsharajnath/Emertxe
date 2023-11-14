#include <stdio.h>
void print_array(int **p)
{
    int i;
    for (i = 0; i < 3; i++)
    {
	printf("%d ", *p[i]);
	printf("at %p\n", p[i]);
    }
}
int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int *ptr[3] = {&a, &b, &c};
    print_array(ptr);
    return 0;
}
