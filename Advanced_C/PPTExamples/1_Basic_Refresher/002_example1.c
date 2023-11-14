#include <stdio.h>
int main()
{
    char option;
    int age;
    float height;

    printf("Enter a character: \n");
    scanf("%c", &option);
    printf("The character is %c\n", option);
    printf("Enter an integer: \n");
    scanf("%d", &age);
    printf("The integer is %d\n", age);
    printf("Enter a float number: \n");
    scanf("%f", &height);
    printf("The float is %f\n", height);

    return 0;
}
