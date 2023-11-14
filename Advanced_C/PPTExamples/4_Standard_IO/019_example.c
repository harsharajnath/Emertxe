#include <stdio.h>
int main()
{
    int age;
    char array_1[10];
    char array_2[10];
    sscanf("I am 30 years old", "%s %s %d", array_1, array_2, &age);
    sscanf("I am 30 years old", "%*s %*s %d", &age);
    printf("OK you are %d years old\n", age);
    return 0;
}
