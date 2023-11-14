/*


Name: Harsharaj Nath
Date of Submission: 25-11-22
Description: WAF to create hash table, to search data, to insert and delete element in hash table. Also to delete entire hash table.


Sample execution: -

1. Create hash table
Input:	Array size = 5
Output:	Hash table with the given size

Hash table
0 → -1

1 → -1

2 → -1

3 → -1

4 → -1

2. Hash table insert
Hash table
0 → 25

1 → 51 → 21 -> 11

2 → 27

3 → 23 → 43

4 → -1

3. Hash table search
4. Hash delete element
5. Hash Table delete
6. Hash Table display


#########################################_Program_begins_from_here_######################################### */


#include"hash.h" 

int main()
{
    int size, data, choice, index;
    char opt;
    printf("Enter the size of arr: ");
    scanf("%d", &size);
    hash_t arr[size];
    create_HT(arr, size);

    printf("1. Insert data in HT\n2. Search data in HT\n3. Delete data from HT\n4. Destroy HT\n5. Display HT\n6. Exit\nEnter you choice : ");
    while(1)
    {
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1:
		printf("Enter the data: ");
		scanf("%d", &data);
		if(insert_HT(arr, data, size) == FAILURE)
		{
		    printf("INFO : Insert data is Failure\n");
		}

		break;

	    case 2:
		printf("Enter the data: ");
		scanf("%d", &data);
		if((search_HT(arr, data, size)) == DATA_NOT_FOUND)
		{
		    printf("INFO : Data not found\n");
		}
		else
		{
		    printf("INFO : %d is found at the index %d\n", data, data % size);
		}
		break;

	    case 3:
		printf("Enter the data: ");
		scanf("%d", &data);
		if(delete_element(arr, data, size) == DATA_NOT_FOUND)
		{
		    printf("INFO : Data is not found\n");
		}
		else
		{
		    printf("INFO : %d is deleted successfully\n",data);
		}
		break;

	    case 4:
		if(destroy_HT(arr,size) == SUCCESS)
		{
		    printf("INFO: Hashtable deleted successfully\n");
		}
		else
		{
		    printf("INFO: Delete hashtable is Failure\n");
		}
		break;

	    case 5:
		display_HT(arr, size);
		break;
	    case 6:
		return SUCCESS;

	    default:
		printf("Invalid input\n");
	}
    }
}
