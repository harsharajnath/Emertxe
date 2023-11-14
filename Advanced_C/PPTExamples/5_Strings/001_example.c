#include<stdio.h>
int main()
{
    char char_array[5] = {'H', 'E', 'L', 'L', 'O'};
    printf("%s\n", char_array);
    
    char str1[6] = {'H', 'E', 'L', 'L', 'O', '\0'};
    printf("%s\n", str1);
    
    char str2[] = {'H', 'E', 'L', 'L', 'O', '\0'};
    printf("%s\n", str2);
    
    //char str3[6] = {"H", "E", "L", "L", "O"};
    
    char str4[6] = {"H" "E" "L" "L" "O"};
    printf("%s\n", str4);
    
    char str5[6] = {"HELLO"};
    printf("%s\n", str5);
    
    char str6[6] = "HELLO";
    printf("%s\n", str6);
    
    char str7[] = "HELLO";
    printf("%s\n", str7);
    
    char *str8 = "HELLO";
    printf("%s\n", str8);

    return 0;
}
