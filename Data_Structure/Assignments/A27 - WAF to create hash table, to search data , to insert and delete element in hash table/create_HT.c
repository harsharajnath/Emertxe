#include "hash.h"

/* Function to create Hash Table */
void create_HT(hash_t *HT, int size)
{
    for(int i = 0; i < size; i++)
    {
	HT[i].index = i;    //index
	HT[i].value = -1;   //value
	HT[i].link = NULL;  //link
    }
}
