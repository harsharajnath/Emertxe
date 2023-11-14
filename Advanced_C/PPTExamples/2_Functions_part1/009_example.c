#include <stdio.h>
int *modify_array(int *array, int size);
void print_array(int array[], int size);
int main()
{
    int array[5] = {10, 20, 30, 40, 50};
    int *new_array_val;
    new_array_val = modify_array(array, 5);
    print_array(new_array_val, 5);
    return 0;
}

void print_array(int array[], int size)
{
    int iter;

    for (iter = 0; iter < size; iter++)
    {
	printf("Index %d has Element %d\n", iter, array[iter]);
    }
}

int *modify_array(int *array, int size)
{
    int iter;
    for (iter = 0; iter < size; iter++)
    {
	*(array + iter) += 10;
    }
    return array;
}
