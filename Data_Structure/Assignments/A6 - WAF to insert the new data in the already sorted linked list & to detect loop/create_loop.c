#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
    int data_found_flag = 0;

    //check if list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    //create local referece pointer
    Slist *temp = *head;
    Slist *data_found;


    //travering through the list till last node
    while(temp -> link != NULL)
    {
	if(temp -> data != data)      //if data does not matches
	{
	    temp = temp -> link;        //increment the temp pointer
	}
	else        //if data matches
	{
	    //setting the flag
	    data_found_flag = 1;

	    //storing the address of temp node for future linking
	    data_found = temp;

	    //incrementing the temp pointer
	    temp = temp -> link;
	}
    }


    //when last node is reached
    if(temp -> link == NULL)
    {
	//if data not matched till the last node
	if(data_found_flag == 0)
	{
	    //checking if last node data matches
	    if(temp -> data == data)
	    {
		//creating the loop
		temp -> link = temp;
		return SUCCESS;
	    }
	    else
	    {
		//data not found
		return DATA_NOT_FOUND;
	    }
	}
	//if data matched already
	else
	{
	    //updating the last node link to the data matched node
	    temp -> link = data_found;
	    return SUCCESS;
	}
    }
}
