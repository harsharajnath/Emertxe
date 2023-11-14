#include<stdio.h>

/* Program to find whether character is Uppercase, Lowercase, Digit or None of these */

int main()
{
    char character;
    printf("\n**Program to find whether character is Uppercase, Lowercase, Digit or None of these**\n\n");
    printf("Enter the character: \n");
    scanf("%c", &character);

    if ( character >= 97 && character <= 122 )
    {
	printf("You entered a lower case character\n");
    }
    else if ( character >= 65 && character <= 90 )
    {
	printf("You entered an upper case character\n");
    }
    else if ( character >= 48 && character <= 57 )
    {
	printf("You entered a digit\n");
    }
    else
    {
	printf("You entered a special character\n");
    }

    return 0;
}
