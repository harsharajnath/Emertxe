#include <stdio.h>
void print_array( int *array, int size );
int main()
{
    int array[5] = {10, 20, 30, 40, 50};
    print_array(array, 5);
    return 0;
}

void print_array(int *array, int size)
{
    int iter;
    for (iter = 0; iter < size; iter++)
    {
	printf("Index %d has Element %d\n", iter, *array++);
    }
}
