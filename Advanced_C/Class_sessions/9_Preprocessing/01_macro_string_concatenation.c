#include <stdio.h>
#define PRINT(x)	x##_val

int main()
{
    int int1_val = 10;
    float float1_val = 20.5;

    printf("integer is --> %d, float is --> %f\n", PRINT(int1), PRINT(float1));

    return 0;
}
