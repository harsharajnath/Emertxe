#include<stdio.h>

int main()
{
    static int count = 0;

    static int num;

    if (count == 0)
        num = 10;

    if (num > 5)

    {

        printf("%d\n", num--);
        count++;
        main(num);
    } else

        printf("%d\n", num);

    return 0;
}