#include<stdio.h>

int main()

{

    static int i = 5;
    printf("%d\n", i);
    if(i!= 0)

    {

        i--;
        main();

    }
    printf("%d\n", i);

    return 0;

}