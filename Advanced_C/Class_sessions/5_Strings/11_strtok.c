#include<stdio.h>
#include<string.h>
int main()
{
    char str1[] = "Hi;Hello::How>?are;:you?";
    char str2[] = ":;><?.";

    char *token;
    token = strtok(str1, str2);
    while(token != NULL)
    {
	printf("%s\n", token);
	token = strtok(NULL, str2);
    }
    return 0;
}
