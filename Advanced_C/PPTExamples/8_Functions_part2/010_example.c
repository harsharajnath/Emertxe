#include<stdio.h>
#include<stdlib.h>
int sa(const void *a, const void *b)
{
    return *(int *) a > *(int *) b;
}
int sd(const void *a, const void *b)
{
    return *(int *) a < *(int *) b;
}
void print(int *a, unsigned int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
	printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int a[5] = {9, 2, 6, 1, 7};
    qsort(a, 5, sizeof(int), sa);
    print(a,5);

    qsort(a, 5, sizeof(int), sd);
    print(a,5);

    return 0;
}
