#include<stdio.h>

void print(int self_call)

{
    if(self_call++ != 5)

    {

        printf("main was called %d times \n", self_call);
        print(self_call);

    } else

        printf("\n");
    
    printf("main was called %d times \n", self_call);

}

int main()
{
    int self_call = 0;
    print(self_call);
    return 0;
}