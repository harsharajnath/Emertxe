#include"hash.h"

void display_HT(hash_t *arr, int size)
{
    hash_t *temp;
    for(int i = 0; i < size; i++)
    {
	printf("[%d] - %d", i, arr[i].value);
	temp = arr[i].link;
	while(temp)
	{
	    printf(" -> %d",temp->value);
	    temp = temp->link;
	}
	printf("\n");
    }
}
