#include "main.h"

/* Function to sort the array using heap sort */
int heap_sort(int *heap, int size)
{
    //variable declaration
    int index, swap;

    //updating index value
    index = size - 1;

    while(index >= 0)
    {
	// swap heap[0] and heap[index]
	swap = heap[0];
	heap[0] = heap[index];
	heap[index] = swap;

	// function call for max_heap()
	max_heap(heap, 0, index);

	// decrementing the index
	index--;
    }
}
