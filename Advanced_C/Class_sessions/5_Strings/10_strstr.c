#include<stdio.h>
#include<string.h>
int main()
{
    char haystack[] = "Hi Hello how are you ?";
    char needle[] = "how";
    char *ptr;
    ptr = strstr(haystack, needle);
    if ( ptr == NULL )
    {
	printf("String is not found\n");
	return 1;
    }
    else
	printf("String is found at %s\n", ptr);

    return 0;
}
