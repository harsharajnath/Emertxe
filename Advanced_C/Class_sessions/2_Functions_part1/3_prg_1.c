#include<stdio.h>

int main()

{

    static int self_call = 0;

    if(self_call++ != 99)
    {
        printf("main was called %d times \n", self_call);

        main();
    }
    else
        printf("\n");

    return 0;
}