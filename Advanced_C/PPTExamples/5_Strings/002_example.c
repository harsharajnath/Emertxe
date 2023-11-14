#include <stdio.h>
int main()
{
    char char_array_1[5] = {'H', 'E', 'L', 'L', 'O'};
    char char_array_2[] = "Hello";
    printf("%zu\n", sizeof(char_array_1));
    printf("%zu\n", sizeof(char_array_2));
    return 0;
}
