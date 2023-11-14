#include<stdio.h>
void swap(void *ptr1, void *ptr2, int size)
{
    char temp;
    int i;
    for ( i=0; i<size; i++)
    {
	temp = *(char *)ptr1;
	*(char *)ptr1 = *(char *)ptr2;
	*(char *)ptr2 = temp;
	ptr1++;
	ptr2++;
    }
}
int main()
{
    int num1 = 10, num2 = 20;
    float f1 = 10.95, f2 = 2.65;

    printf("Before swapping: \n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(num1));
    printf("After swapping: \n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    printf("Before swapping: \n");
    printf("f1 = %g, f2 = %g\n", f1, f2);
    swap(&f1, &f2, sizeof(f1));
    printf("After swapping: \n");
    printf("f1 = %g, f2 = %g\n", f1, f2);

    return 0;
}
