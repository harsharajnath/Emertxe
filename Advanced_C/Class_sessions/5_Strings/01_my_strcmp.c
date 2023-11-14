#include<stdio.h>
#include<stdio_ext.h>

int my_strcmp(char *str1, char *str2)
{
    while( *str1 == *str2 && *str1 != '\0' && *str2 != '\0' )
    {
	str1++;
	str2++;
    }
    if ( *str1 == *str2 )
	return 0;
    else return *str1 - *str2;
}

int main()
{
    char str1[20], str2[20];
    int ret;
    
    printf("Enter the string1: \n");
    scanf("%19[^\n]", str1);
    
    __fpurge(stdin);
    
    printf("Enter the string2: \n");
    scanf("%19[^\n]", str2);
    
    ret = my_strcmp(str1,str2);
    
    if(ret == 0)
	printf("Both the strings are equal\n");
    else if (ret > 0)
	printf("string1 is greater than string2\n");
    else
	printf("string2 is greater than string1\n");

    return 0;
}
