#include <stdio.h>
#define SIZE 1024
#define MSG "Enter a string"

int main()
{
    char array[SIZE];

    printf("%s\n", MSG);
    fgets(array, SIZE, stdin);

    printf("%s\n", array);

    return 0;
}
