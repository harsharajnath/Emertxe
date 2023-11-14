#include<stdio.h>
#include<stdlib.h>
int main()
{
    int row, col;
    printf("Enter the no. of Rows:\n");
    scanf("%d", &row);					//taking row value

    printf("Enter the no. of Columns:\n");
    scanf("%d", &col);					//taking col value

    int (*aptr)[col];					//pointer to the first 1D array

    aptr = malloc(sizeof(*aptr) * row);			//dynamically allocating memory for 2D array

    printf("Enter the array elements\n");
    for(int i = 0; i < row; i++)
    {
	for(int j = 0; j < col; j++)
	{
	    scanf("%d", &aptr[i][j]);			//reading the array elements
	}
    }



    printf("Array is\n");
    for(int i = 0; i < row; i++)
    {
	for(int j = 0; j < col; j++)
	{
	    printf("%d ", aptr[i][j]);			//printing the array elements
	}						  
	printf("\n");
    }
    printf("\n");

    printf("Address contained by aptr is %p\n", aptr);

    free(aptr);							//freeing the memory
    aptr = NULL;

    printf("Address contained by aptr is %p\n", aptr);


    return 0;
}

