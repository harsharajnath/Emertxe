#include <stdio.h>
int main()
{
    char *str1 = "Hello";
    char *str2 = "Hello";
    if (str1 == str2)
    {
	printf("Hoo. They share same space\n");
    }
    else
    {
	printf("No. They are in different space\n");
    }
    return 0;
}
