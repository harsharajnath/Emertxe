/*

#include <stdio.h>
int main()
{
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 40;
    int num5 = 50;
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    printf("%d\n", num4);
    printf("%d\n", num5);
    return 0;
}


*/


#include <stdio.h>
int main()
{
    int num_array[5] = {10, 20, 30, 40, 50};
    int index;
    for (index = 0; index < 5; index++)
    {
	printf("%d\n", num_array[index]);
    }
    return 0;
}
