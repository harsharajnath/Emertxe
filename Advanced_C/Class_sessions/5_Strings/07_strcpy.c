#include<stdio.h>
#include<string.h>
int main()
{
    char str1[20], str2[20];
    printf("Enter the string1:\n");
    scanf("%19[^\n]", str1);

    strcpy(str2, str1);
    printf("Destination is %s\n", str2);

    return 0;
}
