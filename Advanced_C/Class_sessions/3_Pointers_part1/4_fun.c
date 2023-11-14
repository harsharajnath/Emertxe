#include <stdio.h>

void modify(int *ptr1, int *ptr2)

{

    *ptr1 = *ptr1 + 1;
    *ptr2 = *ptr2 + 1;

}

int main()
{
    int num1 = 10, num2 = 20;

    printf("Before Modification\n");
    printf("num1 is %d, num2 is %d\n", num1, num2);

    modify(&num1, &num2);

// num2 modify (num1, num2);

    printf("After Modification\n");
    printf("num1 is %d, num2 is %d\n", num1, num2);

    return 0;
}