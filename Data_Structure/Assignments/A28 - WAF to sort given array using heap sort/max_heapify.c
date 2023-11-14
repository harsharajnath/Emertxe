#include "main.h"

/* Function to check the number is minimum or maximum to decide the position */
void max_heap(int *heap, int i, int size)
{
    // variable declaration
    int left, right, large, swap;

    // updating value of left and right
    left = 2 * i + 1;
    right = 2 * i + 2;

    if((heap[i] < heap[left]) && (left < size))
    {
	// updating large
	large = left;
    }
    else
    {
	// updating large
	large = i;
    }

    if((heap[large] < heap[right]) && (right < size))
    {
	// updating large
	large = right;
    }

    // if index is not equal to large
    if(i != large)
    {
	// swap heap[large] and heap[i]
	swap = heap[large];
	heap[large] = heap[i];
	heap[i] = swap;

	// recursive function call
	max_heap(heap, large, size);
    }
}
