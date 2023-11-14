/*


Name: Harsharaj Nath
Date of Submission: 12-08-22
Description: WAP to Implement the student record using array of structures


Sample execution:

Test Case 1:

Enter no.of students : 2
Enter no.of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Science
----------Enter the student datails-------------
Enter the student Roll no. : 1
Enter the student 1 name : Nandhu
Enter Maths mark : 99
Enter Science mark : 91
----------Enter the student datails-------------
Enter the student Roll no. : 2
Enter the student 2 name : Bindhu
Enter Maths mark : 88
Enter Science mark : 78
----Display Menu----
1. All student details
2. Particular student details
Enter your choice : 2

----Menu for Particular student----
1. Name.
2. Roll no.
Enter you choice : 1
Enter the name of the student : Nandhu
Roll No.   Name           Maths         Science       Average       Grade
1          Nandhu         99            91            95            A
Do you want to continue to display(Y/y) : n


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char *, char *);                                                  //function prototype of my_strcmp() function
void grade(float);                                                              //function prototype of grade() function
void print_header(int, char (* )[20]);                                          //function prototype of print_header() function

struct student_record                                                           //structure definition
{                                                                               
    int roll_no;
    char name[30];
    int marks[20];
    float avg;
};

int main()
{
    int no_stu, no_sub, cmp, index1, index2, stu_roll, roll_verify;             //variable declaration
    int menu_choice1, menu_choice2;
    char stu_name[30];
    char display_choice = 'y';

    char (*sub_name)[20];                                                       //pointer to an array for subject names

    printf("Enter no.of students : ");
    scanf("%d", &no_stu);                                                       //taking no. of students from user

    struct student_record S[no_stu];                                            //declaring array of structure

    printf("Enter no.of subjects : ");
    scanf("%d", &no_sub);                                                       //taking no. of subjects from user

    sub_name = malloc(sizeof(*sub_name) * no_sub);                              //dynamically allocating memory according to no. of subjects

    for(int i = 0; i < no_sub; i++)                                             //loop to read N no. of subject names
    {
	printf("Enter the name of subject %d : ", (i + 1));
	scanf(" %[a-z A-Z]", *(sub_name + i));                                  //reading the subject name
    }

    for(int i = 0; i < no_stu; i++)                                             //loop to read N no. of student details
    {
	int check = 0;                                                          //variable initialization
	int sum = 0;

	printf("----------Enter the student datails-------------\n");

	if(i == 0)                                                              //if taking the record 1st time, store the roll no. directly
	{
	    printf("Enter the student Roll no. : ");
	    scanf("%d", &S[i].roll_no);                                         //reading the roll no.
	}
	else                                                                    //else check if the entered roll no. already exist, if yes then prompt to enter again
	{
	    while(check != 1)                                                   //loop till distinct roll no. is entered
	    {
		int roll_found_flag = 0;                                        //flag initialization

		printf("Enter the student Roll no. : ");
		scanf("%d", &roll_verify);                                      //reading the roll no.

		for(int j = 0; j < i; j++)                                      //loop to check if entered roll no. already exist
		{
		    if(roll_verify == S[j].roll_no)
		    {
			roll_found_flag = 1;
			break;
		    }
		}

		if (roll_found_flag == 1)                                       //if flag is set means entered roll already exist, prompt to enter again
		{
		    printf("Roll no. already present, please try again\n");
		}
		else                                                            //if distinct roll no. is entered, storing the roll no.
		{
		    S[i].roll_no = roll_verify;                                 //storing the roll no.
		    check = 1;
		}
	    }
	}

	printf("Enter the student %d name : ", (i + 1));
	scanf(" %[a-z A-Z]", S[i].name);                                        //reading student name

	for (int j = 0; j < no_sub; j++)                                        //reading N subject marks
	{
	    printf("Enter %s mark : ", *(sub_name + j));
	    scanf("%d", S[i].marks + j);
	}

	for (int k = 0; k < no_sub; k++)                                        //calculating the sum of all marks
	{
	    sum = sum + S[i].marks[k];
	}

	S[i].avg = (float)sum / no_sub;                                         //storing the average
    }

    do{                                                                                                                     //loop for displaying student details till user press y/Y
	printf("\n----Display Menu----\n1. All student details\n2. Particular student details\nEnter your choice : ");
	scanf("%d", &menu_choice1);                                                                                         //reading choice from user

	switch(menu_choice1)
	{
	    case 1:                                                             //case 1 is for All student details

		print_header(no_sub, sub_name);                             //function call

		for(int i = 0; i < no_stu; i++)                             //loop to print Roll no., Name, Marks, Average and Grade for N studenta
		{   
		    /*--------------------------------------------*/
		    /*-----------Printing the details-------------*/

		    printf("%-15d %-30s", S[i].roll_no, S[i].name);

		    for(int j = 0; j < no_sub; j++)
		    {
			printf("%-20d", S[i].marks[j]);
		    }

		    printf("%-23.2f", S[i].avg);

		    grade(S[i].avg);                                        //function call

		    /*--------------------------------------------*/
		}

		break;

	    case 2:                                                             //case 2 is for Particular student details

		printf("----Menu for Particular student----\n1. Name\n2. Roll no.\nEnter you choice : ");
		scanf("%d", &menu_choice2);                                                                             //reading choice from user

		if(menu_choice2 == 1)                                       //student details according to name
		{
		    int if_name_found = 0;                                  //flag initialization
		    int print_headr = 0;

		    printf("Enter the name of the student : ");
		    scanf(" %[a-z A-Z]", stu_name);                         //reading name to be searched, from the user

		    for(int i = 0; i < no_stu; i++)                         //loop to search for name in the records and printing all matched found
		    {
			cmp = my_strcmp(stu_name, S[i].name);               //function call

			if(cmp == 0)                                        //if matched found
			{
			    print_headr++;

			    if(print_headr == 1)                            //in this way, prints the header only one time and only when match is found
			    {
				print_header(no_sub, sub_name);             //function call
			    }
			    /*--------------------------------------------*/
			    /*-----------Printing the details-------------*/

			    printf("%-15d %-30s", S[i].roll_no, S[i].name);

			    for(int j = 0; j < no_sub; j++)
			    {
				printf("%-20d", S[i].marks[j]);
			    }

			    printf("%-23.2f", S[i].avg);

			    grade(S[i].avg);                                //function call

			    /*--------------------------------------------*/
			    if_name_found++;
			}

		    }

		    if(if_name_found == 0)
		    {
			printf("***Name NOT found***\n");                   //error message
		    }


		}
		else if (menu_choice2 == 2)                                 //student details according to roll no.
		{
		    int if_roll_found = 0;                                  //flag initialization

		    printf("Enter the roll no. of the student : ");
		    scanf("%d", &stu_roll);                                 //reading roll no. to be searched, from the user

		    for(int i = 0; i < no_stu; i++)                         //loop to search for roll no. in the records
		    {
			if(stu_roll == S[i].roll_no)                        //if found, storing the roll no. in index
			{
			    index2 = i;
			    if_roll_found = 1;

			    break;
			}
		    }

		    if(if_roll_found == 1)                                  //when roll no. found, print the records
		    {

			print_header(no_sub, sub_name);                     //function call

			/*--------------------------------------------*/
			/*-----------Printing the details-------------*/

			printf("%-15d %-30s", S[index2].roll_no, S[index2].name);

			for(int j = 0; j < no_sub; j++)
			{
			    printf("%-20d", S[index2].marks[j]);
			}

			printf("%-23.2f", S[index2].avg);

			grade(S[index2].avg);                               //function call

			/*--------------------------------------------*/
		    }
		    else
		    {
			printf("***Roll no. NOT found***\n");               //error message
		    }

		}
		else
		{
		    printf("Error: invalid option\n");                      //error essage
		}

		break;

	    default:
		printf("Error: invalid option\n");
	}

	printf("\nDo you want to continue to display? (Y/y) : ");
	scanf(" %c", &display_choice);                                          //reading choice from user

    }while( display_choice == 'Y' || display_choice == 'y');

    free(sub_name);                                                             //freeing the dynamically allocated memory
    sub_name = NULL;

    return 0;
}

int my_strcmp(char *str1, char *str2)                                           //function definition for my_strcmp() - Function to compare two strings
{
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
	str1++;
	str2++;
    }                                                                           //  logic

    if (*str1 == *str2)
	return 0;
    else
	return *str1 - *str2;
}

void print_header(int no_sub, char (*sub_name)[20])                             //function definition for print_header() - function to print the header
{
    printf("%-15s %-30s", "Roll No.", "Name");

    for (int i = 0; i < no_sub; i++)
    {
	printf("%-20s", *(sub_name + i));
    }

    printf("%-22s %-17s\n", "Average", "Grade"); 
}

void grade(float avg)                                                           //function definition for grade() - function to print the grade
{
    if( avg >= 90 )
    {
	printf("%-18c\n", 'A');
    }
    else if(avg >= 80 &&  avg < 90 )
    {
	printf("%-18c\n", 'B');
    }
    else if(avg >= 70 &&  avg < 80 )
    {
	printf("%-18c\n", 'C');
    }
    else if(avg >= 60 &&  avg < 70 )
    {
	printf("%-18c\n", 'D');
    }
    else if(avg >= 35 &&  avg < 60 )
    {
	printf("%-18c\n", 'E');
    }
    else
    {
	printf("%-18s\n", "Fail");
    }
}
