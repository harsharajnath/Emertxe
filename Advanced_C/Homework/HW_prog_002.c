#include<stdio.h>

/* Program to print the grade for a given percentage */

int main()
{
    float percentage;
    printf("\n**Program to print the grade for a given percentage**\n\n");
    printf("Enter the percentage: \n");
    scanf("%f", &percentage);
    
    if ( percentage  >= 90 )
    {
	printf("\nGrade: A+\n");
    }
    else if ( percentage >= 80 && percentage < 90 )
    {
	printf("\nGrade: A\n");
    }
    else if ( percentage >= 70 && percentage < 80 )
    {
	printf("\nGrade: B+\n");
    }
    else if ( percentage >= 60 && percentage < 70 )
    {
	printf("\nGrade: B\n");
    }
    else if ( percentage >= 50 && percentage < 60 )
    {
	printf("\nGrade: C\n");
    }
    else if ( percentage >= 40 && percentage < 50 )
    {
	printf("\nGrade: D\n");
    }
    else
    {
	printf("\nFail\n");
    }

    return 0;
}
