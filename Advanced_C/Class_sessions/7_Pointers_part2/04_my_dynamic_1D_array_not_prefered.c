#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the no. of Elements:\n");
    scanf("%d", &n);

    int (*aptr)[n];					//pointer to an array
    aptr = malloc(sizeof(int) * n);			//dynamically allocating memory for array

    printf("Enter the array elements\n");
    for(int i = 0; i < n; i++)
    {
	scanf("%d", aptr[i]);				//reading the array elements
    }

    printf("Array is ");
    for(int i = 0; i < n; i++)
    {
	printf("%d ", *aptr[i]);			//printing the array elements
    }
    printf("\n");

    printf("Address contained by aptr is %p\n", aptr);

    free(aptr);						//freeing the memory
    aptr = NULL;
    
    printf("Address contained by aptr is %p\n", aptr);
    
    
    return 0;
}

