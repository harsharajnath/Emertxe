#include "main.h"

/* Function for build maxheap */
void build_maxheap(int *heap, int size)
{
    // variable declaration
    int index;

    // updating index value
    index = (size/2) - 1;

    while(index >= 0)
    {
	// function call for max_heap()
	max_heap(heap, index, size);

	// decrementing the index
	index--;
    }
}
