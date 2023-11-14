#include <stdio.h>
int main()
{
    int num_array[5] = {1, 2, 3, 4, 5};
    int index;
    index = 0;
    do
    {
	printf("Index %d has Element %d\n", index, num_array[index]);
	index++;
    } while (index < 5);
    return 0;
}
