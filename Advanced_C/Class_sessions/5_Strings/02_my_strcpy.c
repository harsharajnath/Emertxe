#include<stdio.h>

char *my_strcpy(char *dest, char *src)
{
    while(*src)
    {
	*dest = *src;
	src++;
	dest++;
    }
    *dest = *src;
}

int main()
{
    char str1[20], str2[20];
    printf("Enter the string1:\n");
    scanf("%19[^\n]", str1);

    my_strcpy(str2, str1);
    printf("Destination is %s\n", str2);

    return 0;
}



/* Modularity
   
   while(*src)
   {
	 *dest++ = *src++;
   }
   *dest = *src;


   OR


   char *ptr = dest;
   while(*dest++ = *src++);
   return ptr;

*/
