/*



#include <stdio.h>
int main()
{
    int num1 = 10;
    int num2 = 20;
    int num3;
    if (num1 > num2)
    {
	num3 = num1;
    }
    else
    {
	num3 = num2;
    }
    printf("%d\n", num3);

    return 0;
}


*/



#include <stdio.h>
int main()
{
    int num1 = 10;
    int num2 = 20;
    int num3;
    num3 = num1 > num2 ? num1 : num2;
    printf("Greater num is %d\n", num3);
    return 0;
}
