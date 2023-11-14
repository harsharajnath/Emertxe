#include <stdio.h>
int *return_array(void);
void print_array(int *array, int size);
int main()
{
    int *array_val;
    array_val = return_array();
    print_array(array_val, 5);

    return 0;
}

int *return_array(void)
{
    static int array[5] = {10, 20, 30, 40, 50};
    return array;
}

void print_array(int *array, int size)
{
    int iter;

    for (iter = 0; iter < size; iter++)
    {
	printf("Index %d has Element %d\n", iter, array[iter]);
    }
}
